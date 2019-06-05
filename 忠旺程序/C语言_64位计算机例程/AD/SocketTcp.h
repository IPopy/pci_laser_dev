#pragma once
#include <Winsock2.h> //windows socket的头文件



class SocketTcp
{
public:
	// 初始化和绑定端口集成在构造函数中
	SocketTcp(int port=4000) ;
	~SocketTcp() ;

	// 子类通过重写 monitor 方法来实现自己的监听处理
	void monitor();

	char recvBuf[50];
	char sendBuf[90];

protected:
	SOCKET sockSrv;				// 创建 socket
	SOCKADDR_IN addrSrv;		// 地址
	int len;
	SOCKADDR_IN addrClient;
};