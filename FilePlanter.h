#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FilePlanter.h"
#include<QFileDialog>
#include "./LgNetwork/QtTCPServerHandler.h"
#include "ui_userInfo.h"
#include "userInfo.h"
#include "qwidget.h"
#include "qsystemtrayicon.h"
#include "qhostinfo.h"
#include "qsettings.h"
using namespace std;

struct Users {
    QString sIp = "";
    QString userName = "";
    qint32 sPort = 0;
    bool fileRecState = false;
    userInfo *info;

    QString current_file_name = "";
    //一个带有指定用户信息的窗口
    
    void static DeleteNode(QList<Users> user_list,QString sIp) {
        for (int i = 0; i < user_list.size(); i++) {
            if (user_list[i].sIp == sIp) {
                user_list[i].Delete();
                user_list.removeAt(i);
            }
        }
    }

    void Delete() {
        QString sIp = "";
        QString userName = "";
        qint32 sPort = 0;
        bool fileRecState = false;
        info = nullptr;
    }

    bool isEmpty() {
        if (sIp.isEmpty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

class StudentFileTransfer : public QMainWindow
{
    Q_OBJECT

public:
    StudentFileTransfer(QWidget *parent = nullptr);
    ~StudentFileTransfer();
    QList<Users> user_list;
    qint32 seat = 0;
private slots:

    //几个按钮事件
    void on_btn_choosefile_clicked();
    void on_btn_sendfile_clicked();
    void on_btn_userfresh_clicked();

    //接到用户tcp消息
    void RecvClnMsg(const QString& clnAddr, const quint16 clnPort, const QByteArray& bytes);
    //用户离线事件
    void NewDisConn(const QString& clnAddr, const quint16 clnPort);
    //移除用户
    void RemoveUser(QString sIp);
	//向指定用户重新发送文件
	void ReSendingFile(QString sip);
protected:
	void closeEvent(QCloseEvent *events);
private:
    //文件的标题，如果有这个内容则说明当前发送文件给学生端
    const QByteArray file_title = QByteArray("NewFile");
	QString getLocalIp();
    QSystemTrayIcon* trayIcon;
    void addMessage(QString strMessage);
    QtTCPServerHandler *s_tcp;
    void initTcpServerHandler();
	QString current_file_path = "";

    //更新用户列表，将当前列表内的widget清空，然后重新插入widget
    void UpdateUserList();



    void SendFiletoClient(QString sip);
    Ui::StudentFileTransferClass ui;
};
