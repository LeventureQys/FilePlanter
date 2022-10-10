#include "QtTcpBaseHandler.h"
#include <memory>
#include <QtCore/QHash>
#include <QtCore/QMutex>

#pragma pack(1)

struct MsgHeader
{
	/*
	ͷ��12�ֽ�
	[0] = 4;
	[1] = 'H';
	[2] = 'E';
	[3] = 'A';
	[4] = 'D';
	[5] = 0;
	[6] = 0;
	[7] = 0;
	[8] = 0;
	[9] = 0;
	[10] = 0;
	[11] = 0;
	*/
	char gcBaseHeader[12] = { 0 };

	/*
	4�ֽڣ�������Ϣ�����ݳ���+1
	*/
	int nMsgBodyLen = 0;

	/*
	Ԥ���ֽ�
	*/
	char gcReserved[12] = { 0 };
};

void SendTcp(QTcpSocket * pTcpSocket, const QByteArray &bytes)
{
	/* ��Ϣ�ṹ��ͷ + ���� + ��β��0 */
	MsgHeader header;
	header.nMsgBodyLen = bytes.length() + 1;

	QByteArray bytesHeaderInfo((char*)&header, sizeof(MsgHeader));
	pTcpSocket->write(bytesHeaderInfo);

	char *pData = new char[header.nMsgBodyLen];
	memset(pData, 0, header.nMsgBodyLen);
	memcpy_s(pData, header.nMsgBodyLen, bytes.data(), bytes.length());
	for (int i = 0; i < header.nMsgBodyLen; i += 1024)
	{
		pTcpSocket->write(pData + i, qMin(1024, header.nMsgBodyLen - i));
	}

	delete[] pData;
}

// �洢�ṹ
typedef struct tagTCPRecvData
{
	int nExpectSize = 0;	// ������С
	int nRecvedLen = 0;		// ���մ�С
	QByteArray bytes;

	void Clear()
	{
		nExpectSize = 0;
		nRecvedLen = 0;
		bytes.clear();
	}
}TCPRecvData;
using SPTCPRecvData = std::shared_ptr<TCPRecvData>;
QHash<QTcpSocket*, SPTCPRecvData> g_qhsSock2RecvData;
// ������
QMutex g_mtForQhsSock2RecvData;
void ReadTCPMsg(QTcpSocket * pTcpSocket, qint64 &nCountRecvedMsg, fun_Notice funNotice)
{
	QMutexLocker am(&g_mtForQhsSock2RecvData);

	if (!g_qhsSock2RecvData.contains(pTcpSocket))
	{
		SPTCPRecvData spTcpRecvData = std::make_shared<TCPRecvData>();
		g_qhsSock2RecvData.insert(pTcpSocket, spTcpRecvData);
	}
	SPTCPRecvData spTcpRecvData = g_qhsSock2RecvData[pTcpSocket];

	while (pTcpSocket->bytesAvailable() > 0)
	{
		if (0 == spTcpRecvData->nRecvedLen)
		{
			if (pTcpSocket->bytesAvailable() < sizeof(MsgHeader)) return;

			QByteArray bytesHeader = pTcpSocket->read(sizeof(MsgHeader));

			MsgHeader *pHeader = (MsgHeader*)(bytesHeader.data());
			spTcpRecvData->nExpectSize = pHeader->nMsgBodyLen;
		}

		int nBytesAvailable = pTcpSocket->bytesAvailable();
		if (nBytesAvailable > 0)
		{
			int nThisRecv = qMin(nBytesAvailable, spTcpRecvData->nExpectSize - spTcpRecvData->nRecvedLen);
			spTcpRecvData->bytes += pTcpSocket->read(nThisRecv);
			spTcpRecvData->nRecvedLen += nThisRecv;

			// ��ʵ���ǵ��ڣ��Ӵ��ں�Ϊ�˱���...
			if (spTcpRecvData->nRecvedLen >= spTcpRecvData->nExpectSize)
			{
				// ֪ͨ
				if (nullptr != funNotice) funNotice(spTcpRecvData->bytes);

				// ����
				spTcpRecvData->Clear();
			}
		}
	}

	nCountRecvedMsg = spTcpRecvData->nRecvedLen;
}

#pragma pack()