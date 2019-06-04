// AD.cpp : 定义控制台应用程序的入口点。
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

	// 第一次获取 传感器数据代码
	/*Ceju ceju;

	ceju.getInfomation();
	ceju.printtttt();*/

	// 第二次测试，测试四个方法的时间
	//Verify vf;
	//vf.test();

	//char data_str[50];
	//
	//sprintf(data_str, "%.5f" ,0.05);
	
	// 第四次测试
	//Jingducelinag jd;
	//jd.readFile("20190531132639.txt");
	


	system("pause");
	return 0;
}

