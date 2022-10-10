#pragma once
#include <qwidget.h>
#include "ui_userInfo.h"

class userInfo : public QWidget
{
    Q_OBJECT
public:
    userInfo();
    ~userInfo();

    void SetName(QString name);
    void SetSip(QString sip);
    void SetState(bool state);

    Ui::Form ui;
private slots:
    void on_btn_kick_clicked();
	void on_btn_retry_clicked();
signals:
    void KickUserInfo(QString sIp);
	void Retry(QString sIp);
private:
    
    QString sip;
    QString name;
    bool State = false;
};

