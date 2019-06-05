// socket_client.cpp : 定义控制台应用程序的入口点。
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

		//加载套接字库
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

		//创建套接字
		SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientSocket == INVALID_SOCKET)
		{
			cout << "clientSocket = socket(AF_INET, SOCK_STREAM, 0) execute failed!" << endl;
			return -1;
		}

		//初始化服务器端地址族变量
		SOCKADDR_IN srvAddr;
		//srvAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		char addr[20] = "127.0.0.1";	// "192.168.1.106" "127.0.0.1"
		inet_pton(AF_INET, addr, &srvAddr.sin_addr);
		srvAddr.sin_family = AF_INET;
		srvAddr.sin_port = htons(4000);

		//连接服务器
		iRet = connect(clientSocket, (SOCKADDR*)&srvAddr, sizeof(SOCKADDR));
		if (0 != iRet)
		{
			cout << "connect(clientSocket, (SOCKADDR*)&srvAddr, sizeof(SOCKADDR)) execute failed!" << endl;
			return -1;
		}

		

		//发送消息
		char sendBuf[100];
		//sprintf_s(sendBuf, "Hello, This is client %s", "兔子");
		sprintf_s(sendBuf, "b100x");
		send(clientSocket, sendBuf, strlen(sendBuf) + 1, 0);

		//接收消息
		char recvBuf[100];
		recv(clientSocket, recvBuf, 100, 0);
		printf("%s\n", recvBuf);

		//清理
		closesocket(clientSocket);
		WSACleanup();

		system("pause");
		return 0;
}

