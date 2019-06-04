// AD.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

#pragma comment(lib,"Usb_Daq_V52_Dll.lib")

#include   "Usb_Daq_V52_Dll.h"

using std::cout;
using std::endl;
#define NX  1024
#define Nchannel  8
//#define data_num  NX*Nchannel;
float dataIn[NX*Nchannel];
int main()
{
	int device_num = 10;
	int a=0;

	for (int i = 0; i < 1000000; i++) {}
	if (openUSB()!=0)
	{
		return -1;
	}

	cout << "after usb after usb openafter usb open after usb open " << endl;
	for (int i = 0; i < 10000; i++) {}
	a = 1;
	//closeUSB();
	get_device_num();

	

	int data_num = NX*Nchannel;
	//ad_continu_conf(int ad_os, ad_range,ch_first, ch_last, freq, trig_sl, trig_pol, clk_sl, ext_clk_pol)
	if (ad_continu_conf(0,0, 0, 20000, 0, 0, 0, 0) == -1)
		return -1;

	while (Get_AdBuf_Size(0)<data_num)
	{
		for (int i = 0; i < 10000; i++) {}
	}
	Read_AdBuf(0,dataIn, data_num);
	
	
	AD_continu_stop(0);

	 closeUSB();

	


	
	return 0;
}

