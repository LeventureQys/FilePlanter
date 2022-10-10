#include "FilePlanter.h"

StudentFileTransfer::StudentFileTransfer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    s_tcp = new QtTCPServerHandler(this);
    this->initTcpServerHandler();
	//获得本机的ip，并建立连接
	this->s_tcp->Open(7777);
}

StudentFileTransfer::~StudentFileTransfer()
{
    s_tcp->Close();
    delete s_tcp;

    
}
void StudentFileTransfer::on_btn_choosefile_clicked()
{
    try {
        QString file_path = QFileDialog::getOpenFileName(this, QStringLiteral("请选择需要发送的文件"), "C:", QStringLiteral("任何文件(*)"));
        if (!file_path.isEmpty()) {
            this->ui.line_file->setText(file_path);
        }
        //状态全清零，并重试链表
        foreach(Users temp_user, user_list) {
            temp_user.fileRecState = false;
			temp_user.info->SetState(false);
        }

        this->UpdateUserList();
    }catch (exception &e) {
        qDebug() << e.what();
    }
}
void StudentFileTransfer::on_btn_sendfile_clicked()
{
    if (!this->ui.line_file->text().isEmpty()) {
        QFile temp_file(this->ui.line_file->text());

        if (temp_file.exists()) {
            //此时需要缓存文件了，将文件转为二进制码流，同时开始进行传输工作
            QByteArray file_array;
            QFileInfo file_info(temp_file);
			temp_file.open(QIODevice::ReadOnly);
            file_array = file_title + "|" + file_info.fileName().toLocal8Bit() + "|" + temp_file.readAll();
            //准备发送文件，发送给全体成员，等待消息回复，并重置整个列表
            this->s_tcp->SendMsg(file_array, "", 0);           

            this->addMessage("Try SendFile to Client:" + file_info.fileName());

        }
    }
}
void StudentFileTransfer::on_btn_userfresh_clicked()
{
    ////临时添加一个人的内测按钮 

    //Users user_node;
    //user_node.sIp = QString::number(this->seat++);
    //user_node.sPort = 2333;
    //user_node.userName = "strValues[3]";

    ////反正新加入的用户不管说什么都不可能已经接到文件了不是吗
    //user_node.fileRecState = false;

    //userInfo* temp_info = new userInfo();
    //temp_info->SetName(user_node.userName);
    //temp_info->SetSip(user_node.sIp);
    //temp_info->SetState(user_node.fileRecState);

    //user_node.info = temp_info;
    //this->user_list.append(user_node);
    //connect(temp_info, SIGNAL(KickUserInfo(QString)), this, SLOT(RemoveUser(QString)));
    //this->addMessage(QString("## New User Comming in : %1").arg(user_node.sIp));
    ////

    this->UpdateUserList();
}
QString StudentFileTransfer::getLocalIp()
{  //获取IPv4地址
	QString hostname = QHostInfo::localHostName();
	QHostInfo hostinfo = QHostInfo::fromName(hostname);
	QString localip = "";
	QList<QHostAddress> addList = hostinfo.addresses();
	if (!addList.isEmpty())
		for (int i = 0; i<addList.size(); i++)
		{
			QHostAddress aHost = addList.at(i);
			if (QAbstractSocket::IPv4Protocol == aHost.protocol())
			{
				localip = aHost.toString();
				break;
			}
		}
	return localip;
}
void StudentFileTransfer::addMessage(QString strMessage)
{
    try {
        if (!strMessage.isEmpty()) {
            this->ui.text_cmd->appendPlainText(strMessage);
        }
    }
    catch (exception& e) {
        qDebug() << "initTcpServerHandler Failed ! :" << e.what();
    }  
}
void StudentFileTransfer::initTcpServerHandler()
{
    try {
        connect(s_tcp, SIGNAL(RecvClnMsg(const QString, const quint16, const QByteArray)), this, SLOT(RecvClnMsg(const QString, const quint16, const QByteArray)));
        connect(s_tcp, SIGNAL(NewDisConn(const QString, const quint16)), this, SLOT(NewDisConn(const QString, const quint16)));
    }
    catch (exception& e) {
        qDebug() << "initTcpServerHandler Failed ! :"<<e.what();
    }
}
void StudentFileTransfer::UpdateUserList()
{
    try {
        //先清空，后添加
        QList<userInfo*> temp = ui.scrollAreaWidgetContents->findChildren<userInfo*>();
        
        for (int i = 0; i < temp.size(); i++) {
            userInfo* si = static_cast<userInfo*>(temp[i]);
            si->setParent(this);
            si->hide();
            //直接删除掉窗口，然后在添加
        }

        for (int i = 0; i < this->user_list.size(); i++) {
            this->ui.scrollAreaWidgetContents->setGeometry(0, 0, this->ui.scrollAreaWidgetContents->width(), 61 * (i+1));
            this->user_list[i].info->setParent(this->ui.scrollAreaWidgetContents);            
            this->user_list[i].info->move(0, 60 * i);
            this->user_list[i].info->show();
        }

        this->addMessage("## Update User List!");
		this->ui.lab_users->setText(QString("当前在线用户:%1人").arg(user_list.size()));
    }
    catch (exception& e) {
        qDebug() << "UpdateUserList Failed ! :" << e.what();
    }    
}
void StudentFileTransfer::ReSendingFile(QString sip)
{
    foreach(Users temp, user_list) {
    
        if (temp.sIp == sip) {
            //将当前文件发送给指定学生 
            temp.info->SetState(false);
            this->SendFiletoClient(sip);
            this->addMessage("Retry Send Message to:" + sip);
            }
    }

}
void StudentFileTransfer::SendFiletoClient(QString sip)
{
    if (!this->ui.line_file->text().isEmpty()) {
        QFile temp_file(this->ui.line_file->text());

        if (temp_file.exists()) {
            //此时需要缓存文件了，将文件转为二进制码流，同时开始进行传输工作
            QByteArray file_array;
            QFileInfo file_info(temp_file);

            file_array = file_title + "|" + file_info.fileName().toLocal8Bit() + "|" + temp_file.readAll();
            //准备发送文件，发送给全体成员，等待消息回复，并重置整个列表
            this->s_tcp->SendMsg(file_array, sip, 0);

            this->addMessage("Try SendFile to Clients:" + file_info.fileName());

        }
    }
}
void StudentFileTransfer::RecvClnMsg(const QString& clnAddr, const quint16 clnPort, const QByteArray& bytes)
{    
    try {
        QString strValue = QString::fromLocal8Bit(bytes);
        QList<QString> strValues = strValue.split('|');

        //收到用户的登录消息，是用户登录的时候需要发送自己的一些信息，比如名字之类的

        if (strValue.contains("NEWCONNECTION")) {
            Users user_node;
            user_node.sIp = clnAddr;
            user_node.userName = strValues[1];

            //反正新加入的用户不管说什么都不可能已经接到文件了不是吗
            user_node.fileRecState = false;

            userInfo *temp_info = new userInfo();
            temp_info->SetName(user_node.userName);
            temp_info->SetSip(user_node.sIp);
            temp_info->SetState(user_node.fileRecState);

            user_node.info = temp_info;
            user_list.append(user_node);

            connect(temp_info, SIGNAL(KickUserInfo(QString)), this, SLOT(RemoveUser(QString)));
			connect(temp_info, SIGNAL(Retry(QString)), this, SLOT(ReSendingFile(QString)));
            this->UpdateUserList();

            //对其返回一个状态
            this->s_tcp->SendMsg("You_Get_Regedited", clnAddr, 0);
        }        
        if (strValue.contains("FILERECIVED")) {
            foreach(Users temp_user, user_list) {
                if (temp_user.sIp == clnAddr) {
                    temp_user.info->SetState(true);
                    this->UpdateUserList();
                }
            }
        }
    }
    catch (exception& e) {
        qDebug() << "RecvClnMsg Failed ! :" << e.what();
    }
}
void StudentFileTransfer::NewDisConn(const QString& clnAddr, const quint16 clnPort)
{
    try {
        //一个用户离线的时候，就将这个用户从链表中移开，并刷新链表
        this->RemoveUser(clnAddr);
    }
    catch (exception& e) {
        qDebug() << "NewDisconn! :" << e.what();
    }
}
void StudentFileTransfer::RemoveUser(QString sIp)
{
    for (int i = 0; i < user_list.size(); i++) {
        if (user_list[i].sIp == sIp) {
            user_list[i].info->setParent(this);
            user_list[i].info->hide();
			user_list[i].info = Q_NULLPTR;
            //通知其退出链接
            this->s_tcp->SendMsg("QUITCONNECT",sIp,0);
            this->addMessage("UserRemoved:" + sIp);
            //删除当前这个用户的user_list
            user_list.removeAt(i);
        }
    }

    this->UpdateUserList();
}

