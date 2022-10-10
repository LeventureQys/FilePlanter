/*!
 * \file QtTcpBaseHandler.h
 *
 * \author daiweiheng
 * \date ���� 2021
 *
 * ����֧��QT�µ�TCP��������ʹ�ô���ǰ��Ҫ����Ŀ���������networkģ��֧��
 */
#pragma once
#include <functional>

#include <QtNetwork/QTcpSocket>

void SendTcp(QTcpSocket * pTcpSocket, const QByteArray &bytes);

using fun_Notice = std::function<void(const QByteArray&)>;
void ReadTCPMsg(QTcpSocket * pTcpSocket, qint64 &nCountRecvedMsg, fun_Notice funNotice);