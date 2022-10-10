#include "userInfo.h"

userInfo::userInfo()
{
	ui.setupUi(this);
}

userInfo::~userInfo()
{

}

void userInfo::SetName(QString name)
{
	if (!name.isEmpty()) {
		this->name = name;
		this->ui.label_2->setText(name);
	}
}

void userInfo::SetSip(QString sip)
{
	if (!sip.isEmpty()) {
		this->sip = sip;
		this->ui.label->setText(sip);
	}
}

void userInfo::SetState(bool state)
{
	this->State = state;
	if (state) {
		this->ui.progressBar->setValue(100);
	}
	else {
		this->ui.progressBar->setValue(0);
	}
}

void userInfo::on_btn_retry_clicked()
{
	emit Retry(this->sip);
}

void userInfo::on_btn_kick_clicked() {
	emit KickUserInfo(this->sip);
}

