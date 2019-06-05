#include "stdafx.h"
#include "ZhongWangDev.h"
#include "OptSoftware.h"
#include "PciLaser.h""

void ZhongWangDev::monitor()
{
	/// 设计，将服务器每次接受到的数据和发送的数据写入 log
	while (1)
	{
		printf("服务端开始监听：");
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);//为一个连接请求提供服务。addrClient包含了发出连接请求的客户机IP地址信息；返回的新socket描述服务器与该客户机的连接

		recv(sockConn, recvBuf, 50, 0);
		printf("从机器人端接收到拍照指令 %s\n", recvBuf);

		// 子类在此添加业务代码

		int length = (sizeof(recvBuf) / sizeof(recvBuf[0]));

		if (recvBuf[0] == 'a')
		{
			choise = OPTSOFTWARE;

			/// 调用 OptSoftware.h 
			OptSoftware os(recvBuf, length);
			os.run();

			sprintf(sendBuf, "y");
		}
		else if (recvBuf[0] == 'b')
		{
			choise = PCILASER;

			/// 调用 PciLaser.h
			PciLaser laser(recvBuf, length);

			float distance = laser.getRealTime(200);
			distance = 5100;
			if (distance == -1)
			{
				distance = 50.5;
			}
			sprintf(sendBuf, "%.5f", distance);
		}
		else
		{
			choise = ROBOTERROR;
			printf("机器人发送数据不正确\n");
		}


		sprintf(sendBuf, sendBuf, inet_ntoa(addrClient.sin_addr));//inet_ntoa网络地址转换转点分十进制的字符串指针
		send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);
		printf("向机器人发送指令 %s\n", sendBuf);

		closesocket(sockConn);
		Sleep(2000);//2000毫秒
	}
	WSACleanup();
}