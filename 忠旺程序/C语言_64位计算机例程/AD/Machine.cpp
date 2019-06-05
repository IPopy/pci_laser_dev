#include "stdafx.h"
#include "Machine.h"


#pragma comment( lib, "ws2_32.lib" )// ����Winsock2.h�ľ�̬���ļ�
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#endif

void Machine::socket_server_Opt()
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

	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);//����socket��AF_INET��ʾ��Internet��ͨ�ţ�SOCK_STREAM��ʾsocket�����׽��֣���Ӧtcp��0ָ������Э��ΪTCP/IP

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //htonl�����������ֽ�˳��ת��Ϊ�����ֽ�˳��(to network long)
													  //INADDR_ANY����ָ����ַΪ0.0.0.0�ĵ�ַ,
													  //��ʾ��ȷ����ַ,�������ַ������
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(4000);//htons�����������ֽ�˳��ת��Ϊ�����ֽ�˳��(to network short)

	::bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//�����ص�ַ�󶨵���������socket�ϣ���ʹ�������ϱ�ʶ��socket

	listen(sockSrv, 5);//socket������׼��������������

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	int record = 3;//��¼��˫
	double odd_data = 0.0;
	double even_data = 0.0;
	int sign = 0;
	OptSoftware os(recvBuf, 50);
	os.recvBuf[0] = 'x';

	while (1)

	{
		printf("����˿�ʼ������");
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);//Ϊһ�����������ṩ����addrClient�����˷�����������Ŀͻ���IP��ַ��Ϣ�����ص���socket������������ÿͻ���������
		
		recv(sockConn, recvBuf, 50, 0);
		printf("�ӻ����˶˽��յ�����ָ�� %s\n", recvBuf);

		int length = (sizeof(recvBuf) / sizeof(recvBuf[0]));


		for (int i = 0; i < length; i++)
		{
			if (recvBuf[i] == 'x')
			{
				os.recvBuf[i] = 'x';
				break;
			}
			else
			{
				os.recvBuf[i] = recvBuf[i];
			}
		}
		os.run();
		sprintf(data_str, "y");

		/*if (recvBuf[0] == 'x')
		{
			sprintf(data_str, "y");
		}
		else
		{
			sprintf(data_str, "file");
		}*/

		char sendBuf[90];

		sprintf(sendBuf, data_str, inet_ntoa(addrClient.sin_addr));//inet_ntoa�����ַת��ת���ʮ���Ƶ��ַ���ָ��
		send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);

		closesocket(sockConn);
		Sleep(2000);//2000����
	}
	WSACleanup();
}

void Machine::socket_server_Jiguang()
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

	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);//����socket��AF_INET��ʾ��Internet��ͨ�ţ�SOCK_STREAM��ʾsocket�����׽��֣���Ӧtcp��0ָ������Э��ΪTCP/IP

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //htonl�����������ֽ�˳��ת��Ϊ�����ֽ�˳��(to network long)
													  //INADDR_ANY����ָ����ַΪ0.0.0.0�ĵ�ַ,
													  //��ʾ��ȷ����ַ,�������ַ������
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(4000);//htons�����������ֽ�˳��ת��Ϊ�����ֽ�˳��(to network short)

	::bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//�����ص�ַ�󶨵���������socket�ϣ���ʹ�������ϱ�ʶ��socket

	listen(sockSrv, 5);//socket������׼��������������

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	int record = 3;//��¼��˫
	double odd_data = 0.0;
	double even_data = 0.0;
	int sign = 0;

	PciLaser laser;
	char buff[50];
	int flag = 0;
	while (1)

	{
		printf("����˿�ʼ������");
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);//Ϊһ�����������ṩ����addrClient�����˷�����������Ŀͻ���IP��ַ��Ϣ�����ص���socket������������ÿͻ���������

		recv(sockConn, recvBuf, 50, 0);
		printf("�ӻ����˶˽��յ�����ָ�� %s\n", recvBuf);

		int length = (sizeof(recvBuf) / sizeof(recvBuf[0]));

		for (int i = 0; i < length; i++)
		{
			if (recvBuf[i] == 'x')
			{
				buff[i] = recvBuf[i];
				flag = 1;
				break;
			}
			else
			{
				buff[i] = recvBuf[i];
			}
		}

		float distance = laser.getRealTime( 200);
		distance = 5100;
		if (distance == -1)
		{
			distance = 50.5;
		}
		sprintf(data_str, "%.5f", distance);
		cout << distance << endl;

		/*if (recvBuf[0] == 'x')
		{
		sprintf(data_str, "y");
		}
		else
		{
		sprintf(data_str, "file");
		}*/

		char sendBuf[90];

		sprintf(sendBuf, data_str, inet_ntoa(addrClient.sin_addr));//inet_ntoa�����ַת��ת���ʮ���Ƶ��ַ���ָ��
		send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);

		closesocket(sockConn);
		if (flag == 1)
			break;
		Sleep(2000);//2000����
	}
	WSACleanup();
}

