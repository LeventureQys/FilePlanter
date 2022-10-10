#include "QtTCPServerHandler.h"
#include "QtTcpBaseHandler.h"

#include <QNetworkInterface>
#include <QThread>

namespace {
	QString getHostIpAddress()
	{
		QString strIpAddress;
		QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
		// 获取第一个本主机的IPv4地址
		int nListSize = ipAddressesList.size();
		for (int i = 0; i < nListSize; ++i)
		{
			if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
				ipAddressesList.at(i).toIPv4Address()) {
				strIpAddress = ipAddressesList.at(i).toString();
				break;
			}
		}
		// 如果没有找到，则以本地IP地址为IP
		if (strIpAddress.isEmpty())
			strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
		return strIpAddress;
	}
}

QtTCPServerHandler::QtTCPServerHandler(QObject *parent) : QObject(parent)
, m_pParent(parent)
{
	//定时五秒发送一个心跳包heartbeat
	connect(&heart_timer, &QTimer::timeout, this, [=]() {
		QByteArray temp = QString("heartbeat").toLocal8Bit();
		this->SendMsg(temp, "", 0);
	});
	heart_timer.start(3000);
}

QtTCPServerHandler::~QtTCPServerHandler()
{
	Close();
}

quint16 QtTCPServerHandler::ServerPort()
{
	if (Q_NULLPTR != m_pTcpServer)
	{
		return m_pTcpServer->serverPort();
	}

	return 0;
}

bool QtTCPServerHandler::Open(const quint16 port)
{
	m_pTcpServer = new QTcpServer(m_pParent);
	//if (!pTcpServer->listen(QHostAddress::LocalHost, port))	// 这种只能处理127.0.0.1的连接
	if (!m_pTcpServer->listen(QHostAddress(::getHostIpAddress()), port))
	{
		qInfo() << QString("监听端口失败：") + QString::number(port);
		return false;
	}
	connect(m_pTcpServer, SIGNAL(newConnection()), this, SLOT(NewConn()));

	return true;
}

void QtTCPServerHandler::Close()
{
	if (Q_NULLPTR != m_pTcpServer)
	{
		m_pTcpServer->close();

		delete m_pTcpServer;
		m_pTcpServer = Q_NULLPTR;
	}

	CloseAllConn();
}

quint16 QtTCPServerHandler::ConnectCount()
{
	return m_qhsSocketCln.size();
}

void QtTCPServerHandler::CloseAllConn()
{
	for (auto it = m_qhsSocketCln.begin(); it != m_qhsSocketCln.end();)
	{
		// close会触发断开处理，断开时会移除键，所以这里不需要删除
		(*it)->pTcpSocket->close();
		//it = m_qhsSocketCln.erase(it);

		it = m_qhsSocketCln.begin();
	}
}

void QtTCPServerHandler::SendMsg(const QByteArray &bytes, QString clnAddr /*= ""*/, quint16 clnPort /*= 0*/)
{
	auto funSend = [&](ClnInfo *pCln) {
		SendTcp(pCln->pTcpSocket, bytes);
		//心跳包不打印
		if (QString::fromLocal8Bit(bytes) != "heartbeat") {
			qInfo() << QString("给%1发送TCP：%2").arg(pCln->qsAddr).arg(QString::fromLocal8Bit(bytes));
		}

	};

	for (auto &item : m_qhsSocketCln)
	{
		if (!clnAddr.isEmpty() && (clnAddr != item->qsAddr)) continue;

		if (clnPort == item->pTcpSocket->peerPort())
		{
			funSend(item);
			break;
		}
		else if (0 == clnPort)
		{
			funSend(item);
		}
	}
}

void QtTCPServerHandler::RecvClnMsg()
{
	QTcpSocket *pTcpSocket = (QTcpSocket*)sender();
	ClnInfo *pClnInfo = m_qhsSocketCln.value((quint16)pTcpSocket, Q_NULLPTR);
	if (Q_NULLPTR == pClnInfo) return;

	QString qsPeerAddr = pClnInfo->pTcpSocket->peerAddress().toString();
	quint16 qnPort = pClnInfo->pTcpSocket->peerPort();

	ReadTCPMsg(pTcpSocket, pClnInfo->nRecvedMsgLen, [&](const QByteArray& bytes) {
		qInfo() << QString("qtnetdll收到来自%1的TCP：%2").arg(qsPeerAddr).arg(QString::fromLocal8Bit(bytes));
		emit RecvClnMsg(qsPeerAddr, qnPort, bytes);
	});
}

void QtTCPServerHandler::NewConn()
{
	QTcpServer *pTcpServer = (QTcpServer*)sender();
	quint16 nServerPort = pTcpServer->serverPort();
	QTcpSocket *pClnTcpSocket = pTcpServer->nextPendingConnection();

	// 登记
	ClnInfo *pNewClnInfo = new ClnInfo;
	pNewClnInfo->pTcpSocket = pClnTcpSocket;
	pNewClnInfo->qsAddr = pClnTcpSocket->peerAddress().toString();
	m_qhsSocketCln.insert((quint16)pClnTcpSocket, pNewClnInfo);

	// 连接信号
	connect(pClnTcpSocket, SIGNAL(readyRead()), this, SLOT(RecvClnMsg()));
	connect(pClnTcpSocket, SIGNAL(disconnected()), this, SLOT(NewDisConn()));
	connect(pClnTcpSocket, &QTcpSocket::disconnected, [=] { pClnTcpSocket->deleteLater(); });

	// 
	qInfo() << QString("qtnetdll新的连接：(%1)").arg(pClnTcpSocket->peerAddress().toString());

	// 发出信号
	emit NewConn(pClnTcpSocket->peerAddress().toString(), pClnTcpSocket->peerPort(), pTcpServer->serverPort());

	//连接成功，发送心跳包
	this->SendMsg("heartbeat", pClnTcpSocket->peerAddress().toString(), pClnTcpSocket->peerPort());

}

void QtTCPServerHandler::NewDisConn()
{
	QTcpSocket *pClnTcpSocket = (QTcpSocket*)sender();

	QMutexLocker lock(&m_qmtForqhsSocketCln);

	QString qsIP = pClnTcpSocket->peerAddress().toString();
	QString qsErr = pClnTcpSocket->errorString();
	qInfo() << QString("qtnetdll新的断开：(%1, %2)").arg(qsIP).arg(qsErr);

	quint16 port = pClnTcpSocket->peerPort();
	emit NewDisConn(qsIP, port);
	emit NewDisConnEx(qsIP, port, qsErr);

	//pClnTcpSocket->deleteLater();

	auto it = m_qhsSocketCln.find((quint16)pClnTcpSocket);
	if (it != m_qhsSocketCln.end())
	{
		m_qhsSocketCln.erase(it);
	}
}
