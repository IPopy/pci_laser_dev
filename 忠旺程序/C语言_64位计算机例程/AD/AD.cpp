// AD.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
//#include <windows.h> 

//#pragma comment(lib,"Usb_Daq_V52_Dll.lib")
//#include   "Usb_Daq_V52_Dll.h"
//#include "time.h"
#include "Ceju.h"
#include "Machine.h"
#include<fstream>
//#include"FileIo.h"
#include <stdio.h>
#include "OptSoftware.h"
#include <TlHelp32.h>
#include <string>
#include "verify.h"
#include "Jingduceliang.h"



int main()
{

	Machine ma;
		//ma.socket_server();
	ma.socket_server_Jiguang();

	// ��һ�λ�ȡ ���������ݴ���
	/*Ceju ceju;

	ceju.getInfomation();
	ceju.printtttt();*/

	// �ڶ��β��ԣ������ĸ�������ʱ��
	//Verify vf;
	//vf.test();

	//char data_str[50];
	//
	//sprintf(data_str, "%.5f" ,0.05);
	
	// ���Ĵβ���
	//Jingducelinag jd;
	//jd.readFile("20190531132639.txt");
	


	system("pause");
	return 0;
}

