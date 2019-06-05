#include "stdafx.h"
#include "ZhongWangDev.h"
#include "OptSoftware.h"
#include "PciLaser.h""

void ZhongWangDev::monitor()
{
	/// ��ƣ���������ÿ�ν��ܵ������ݺͷ��͵�����д�� log
	while (1)
	{
		printf("����˿�ʼ������");
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);//Ϊһ�����������ṩ����addrClient�����˷�����������Ŀͻ���IP��ַ��Ϣ�����ص���socket������������ÿͻ���������

		recv(sockConn, recvBuf, 50, 0);
		printf("�ӻ����˶˽��յ�����ָ�� %s\n", recvBuf);

		// �����ڴ����ҵ�����

		int length = (sizeof(recvBuf) / sizeof(recvBuf[0]));

		if (recvBuf[0] == 'a')
		{
			choise = OPTSOFTWARE;

			/// ���� OptSoftware.h 
			OptSoftware os(recvBuf, length);
			os.run();

			sprintf(sendBuf, "y");
		}
		else if (recvBuf[0] == 'b')
		{
			choise = PCILASER;

			/// ���� PciLaser.h
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
			printf("�����˷������ݲ���ȷ\n");
		}


		sprintf(sendBuf, sendBuf, inet_ntoa(addrClient.sin_addr));//inet_ntoa�����ַת��ת���ʮ���Ƶ��ַ���ָ��
		send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);
		printf("������˷���ָ�� %s\n", sendBuf);

		closesocket(sockConn);
		Sleep(2000);//2000����
	}
	WSACleanup();
}