#pragma once
#include <Winsock2.h> //windows socket��ͷ�ļ�



class SocketTcp
{
public:
	// ��ʼ���Ͱ󶨶˿ڼ����ڹ��캯����
	SocketTcp(int port=4000) ;
	~SocketTcp() ;

	// ����ͨ����д monitor ������ʵ���Լ��ļ�������
	void monitor();

	char recvBuf[50];
	char sendBuf[90];

protected:
	SOCKET sockSrv;				// ���� socket
	SOCKADDR_IN addrSrv;		// ��ַ
	int len;
	SOCKADDR_IN addrClient;
};