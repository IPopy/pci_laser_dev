#include "stdafx.h"
#include "Machine.h"


#pragma comment( lib, "ws2_32.lib" )// 链接Winsock2.h的静态库文件
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#endif

void Machine::socket_server_Opt()
{
	//初始化winsocket
	WORD wVersionRequested;
	WSADATA wsaData;
	WSAStartup(0x0202, &wsaData);
	int err;

	wVersionRequested = MAKEWORD(1, 1);//第一个参数为低位字节；第二个参数为高位字节

	err = WSAStartup(wVersionRequested, &wsaData);//对winsock DLL（动态链接库文件）进行初始化，协商Winsock的版本支持，并分配必要的资源。
	if (err != 0)
	{
		return;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)//LOBYTE（）取得16进制数最低位；HIBYTE（）取得16进制数最高（最左边）那个字节的内容
	{
		WSACleanup();
		return;
	}

	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);//创建socket。AF_INET表示在Internet中通信；SOCK_STREAM表示socket是流套接字，对应tcp；0指定网络协议为TCP/IP

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //htonl用来将主机字节顺序转换为网络字节顺序(to network long)
													  //INADDR_ANY就是指定地址为0.0.0.0的地址,
													  //表示不确定地址,或“任意地址”。”
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(4000);//htons用来将主机字节顺序转换为网络字节顺序(to network short)

	::bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//将本地地址绑定到所创建的socket上，以使在网络上标识该socket

	listen(sockSrv, 5);//socket监听，准备接受连接请求。

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	int record = 3;//记录单双
	double odd_data = 0.0;
	double even_data = 0.0;
	int sign = 0;
	OptSoftware os(recvBuf, 50);
	os.recvBuf[0] = 'x';

	while (1)

	{
		printf("服务端开始监听：");
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);//为一个连接请求提供服务。addrClient包含了发出连接请求的客户机IP地址信息；返回的新socket描述服务器与该客户机的连接
		
		recv(sockConn, recvBuf, 50, 0);
		printf("从机器人端接收到拍照指令 %s\n", recvBuf);

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

		sprintf(sendBuf, data_str, inet_ntoa(addrClient.sin_addr));//inet_ntoa网络地址转换转点分十进制的字符串指针
		send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);

		closesocket(sockConn);
		Sleep(2000);//2000毫秒
	}
	WSACleanup();
}

void Machine::socket_server_Jiguang()
{
	//初始化winsocket
	WORD wVersionRequested;
	WSADATA wsaData;
	WSAStartup(0x0202, &wsaData);
	int err;

	wVersionRequested = MAKEWORD(1, 1);//第一个参数为低位字节；第二个参数为高位字节

	err = WSAStartup(wVersionRequested, &wsaData);//对winsock DLL（动态链接库文件）进行初始化，协商Winsock的版本支持，并分配必要的资源。
	if (err != 0)
	{
		return;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)//LOBYTE（）取得16进制数最低位；HIBYTE（）取得16进制数最高（最左边）那个字节的内容
	{
		WSACleanup();
		return;
	}

	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);//创建socket。AF_INET表示在Internet中通信；SOCK_STREAM表示socket是流套接字，对应tcp；0指定网络协议为TCP/IP

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); //htonl用来将主机字节顺序转换为网络字节顺序(to network long)
													  //INADDR_ANY就是指定地址为0.0.0.0的地址,
													  //表示不确定地址,或“任意地址”。”
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(4000);//htons用来将主机字节顺序转换为网络字节顺序(to network short)

	::bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//将本地地址绑定到所创建的socket上，以使在网络上标识该socket

	listen(sockSrv, 5);//socket监听，准备接受连接请求。

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	int record = 3;//记录单双
	double odd_data = 0.0;
	double even_data = 0.0;
	int sign = 0;

	PciLaser laser;
	char buff[50];
	int flag = 0;
	while (1)

	{
		printf("服务端开始监听：");
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);//为一个连接请求提供服务。addrClient包含了发出连接请求的客户机IP地址信息；返回的新socket描述服务器与该客户机的连接

		recv(sockConn, recvBuf, 50, 0);
		printf("从机器人端接收到拍照指令 %s\n", recvBuf);

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

		sprintf(sendBuf, data_str, inet_ntoa(addrClient.sin_addr));//inet_ntoa网络地址转换转点分十进制的字符串指针
		send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);

		closesocket(sockConn);
		if (flag == 1)
			break;
		Sleep(2000);//2000毫秒
	}
	WSACleanup();
}

