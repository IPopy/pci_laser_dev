// socket_client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <stdio.h>
#include <Winsock2.h>
#include <Ws2tcpip.h>


#pragma comment(lib, "ws2_32.lib")
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS  0

int main()
{

		//�����׽��ֿ�
		WSADATA wsaData;
		int iRet = 0;
		iRet = WSAStartup(MAKEWORD(1, 1), &wsaData);
		if (iRet != 0)
		{
			cout << "WSAStartup(MAKEWORD(2, 2), &wsaData) execute failed!" << endl;
			return -1;
		}
		if (1 != LOBYTE(wsaData.wVersion) || 1 != HIBYTE(wsaData.wVersion))
		{
			WSACleanup();
			cout << "WSADATA version is not correct!" << endl;
			return -1;
		}

		//�����׽���
		SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientSocket == INVALID_SOCKET)
		{
			cout << "clientSocket = socket(AF_INET, SOCK_STREAM, 0) execute failed!" << endl;
			return -1;
		}

		//��ʼ���������˵�ַ�����
		SOCKADDR_IN srvAddr;
		//srvAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		char addr[20] = "127.0.0.1";	// "192.168.1.106" "127.0.0.1"
		inet_pton(AF_INET, addr, &srvAddr.sin_addr);
		srvAddr.sin_family = AF_INET;
		srvAddr.sin_port = htons(4000);

		//���ӷ�����
		iRet = connect(clientSocket, (SOCKADDR*)&srvAddr, sizeof(SOCKADDR));
		if (0 != iRet)
		{
			cout << "connect(clientSocket, (SOCKADDR*)&srvAddr, sizeof(SOCKADDR)) execute failed!" << endl;
			return -1;
		}

		

		//������Ϣ
		char sendBuf[100];
		//sprintf_s(sendBuf, "Hello, This is client %s", "����");
		sprintf_s(sendBuf, "b100x");
		send(clientSocket, sendBuf, strlen(sendBuf) + 1, 0);

		//������Ϣ
		char recvBuf[100];
		recv(clientSocket, recvBuf, 100, 0);
		printf("%s\n", recvBuf);

		//����
		closesocket(clientSocket);
		WSACleanup();

		system("pause");
		return 0;
}

