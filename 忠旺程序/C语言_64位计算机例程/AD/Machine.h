#pragma once
#include <Winsock2.h> //windows socket的头文件
#include "OptSoftware.h"
#include "PciLaser.h"

class Machine
{
public:
	Machine() {};
	~Machine() {};

	void socket_server_Opt();
	void socket_server_Jiguang();

	char recvBuf[50];
	char data_str[60];
};

