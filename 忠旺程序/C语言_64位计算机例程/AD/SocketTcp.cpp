#include "stdafx.h"
#include "SocketTcp.h"

#pragma comment( lib, "ws2_32.lib" )// ����Winsock2.h�ľ�̬���ļ�
#ifndef  _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#endif

SocketTcp::SocketTcp(int port)
{
	//��ʼ��winsocket
	WORD wVersionRequested;
	WSADATA wsaData;
	WSAStartup(0x0202, &wsaData);
	int err;

	wVersionRequested = MAKEWORD(1, 1);//��һ������Ϊ��λ�ֽڣ��ڶ�������Ϊ��λ�ֽ�

	err = WSAStartup(wVersionRequested, &wsaData);//��winsock DLL����̬���ӿ��ļ������г�ʼ����Э��Winsock�İ汾֧�֣��������Ҫ����Դ��
	if (err != 0)
	{
		return;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)//LOBYTE����ȡ��16���������λ��HIBYTE����ȡ��16��������ߣ�����ߣ��Ǹ��ֽڵ�����
	{
		WSACleanup();
		return;
	}

	sockSrv = socket(AF_INET, SOCK_STREAM, 0);//����socket��AF_INET��ʾ��Internet��ͨ�ţ�SOCK_STREAM��ʾsocket�����׽��֣���Ӧtcp��0ָ������Э��ΪTCP/IP

	
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //htonl�����������ֽ�˳��ת��Ϊ�����ֽ�˳��(to network long)
													  //INADDR_ANY����ָ����ַΪ0.0.0.0�ĵ�ַ,
													  //��ʾ��ȷ����ַ,�������ַ������
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port);//htons�����������ֽ�˳��ת��Ϊ�����ֽ�˳��(to network short)

	::bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//�����ص�ַ�󶨵���������socket�ϣ���ʹ�������ϱ�ʶ��socket

	listen(sockSrv, 5);//socket������׼��������������

	
	len = sizeof(SOCKADDR);

	
	
}

SocketTcp::~SocketTcp()
{
	
}


void SocketTcp::monitor()
{
	
	while (1)
	{
		printf("����˿�ʼ������");
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);//Ϊһ�����������ṩ����addrClient�����˷�����������Ŀͻ���IP��ַ��Ϣ�����ص���socket������������ÿͻ���������

		recv(sockConn, recvBuf, 50, 0);
		printf("�ӻ����˶˽��յ�����ָ�� %s\n", recvBuf);

		// �����ڴ����ҵ�����

		int length = (sizeof(recvBuf) / sizeof(recvBuf[0]));

		sprintf(sendBuf, "y");

		char sendBuf[90];

		sprintf(sendBuf, sendBuf, inet_ntoa(addrClient.sin_addr));//inet_ntoa�����ַת��ת���ʮ���Ƶ��ַ���ָ��
		send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);
		printf("������˷���ָ�� %s\n", sendBuf);

		closesocket(sockConn);
		Sleep(2000);//2000����
	}
	WSACleanup();
}