
#include "stdafx.h"
#include "verify.h"
#include "time.h"
#include "FileIo.h"
#include <string>
#include <windows.h>

#pragma comment(lib,"Usb_Daq_V52_Dll.lib")
#include   "Usb_Daq_V52_Dll.h"


#define WRITE_SIZE 8 * 1024 	

using std::cout;
using std::endl;
static float dataIn[WRITE_SIZE];	// 防止出错，数组大小为目标两倍


int findChuanganqi(float data[], int size)
{
	if (size != 8)
		return -1;
	// 确定第一通道的数据在哪里
	float ave;
	float summmm = 0;
	float fangcha[8] = { 0 };
	bool result[8] = { false };
	int counttt = 0;
	int num = 0;
	for (int j = 0; j < size; ++j)
	{
		summmm += data[j];
	}
	ave = summmm / 8;
	for (int j = 0; j < size; ++j)
	{
		fangcha[j] = (ave - dataIn[j]) * (ave - dataIn[j]);
		if (fangcha[j] > 0.1)
		{
			result[j] = true;
			num = j;
			counttt++;
		}
	}
	if (counttt == 1)
		return num;
	else
		return -1;

}

void Verify::test()
{

	// 开始测试
	if (openUSB() != 0)
	{
		return;
	}

	for (int i = 0; i < 10000; i++) {}


	//ad_continu_conf(dev, ad_os, ad_range,ch_first, ch_last, freq, trig_sl, trig_pol, clk_sl, ext_clk_pol)
	FileIo fi;
	string file_name = fi.getCurrentName("devige");
	float dataIn2[WRITE_SIZE];
	int t = 0;
	int size = 0;

	clock_t  clockBegin, clockEnd;
	if (ad_continu_conf(0,0, 0, 20000, 0, 0, 0, 0) == -1)
		return ;

	while (1)
	{
		size = Get_AdBuf_Size(0);

		if (size < WRITE_SIZE)
		{
			Sleep(1);
			continue;
		}
		//cout << size << endl;;

		//for (int i = 0; i < 10000; i++) {}

		int sum = Read_AdBuf(0, dataIn, size);	

		if (t + size/8 > WRITE_SIZE)
		{
			break;
		}
		
		int i = findChuanganqi(dataIn, 8);

		for (; i < size; i += 8)
		{
			dataIn2[t++] = dataIn[i];
		}

		//break;
	}

	cout << "div size:" << t << endl;

	
	fi.write(file_name, dataIn2, t);


	clockBegin = clock();
	AD_continu_stop(0);
	clockEnd = clock();
	stopTime = clockEnd - clockBegin;

	// 自动采集 用时
	clockBegin = clock();	
	if (ad_continu(0, 0, 0, 20000, 0, 0, 0, 0, WRITE_SIZE/8, dataIn) == -1)
		return ;
	clockEnd = clock();
	autoTime = clockEnd - clockBegin;

	file_name = fi.getCurrentName("auto");
	fi.write(file_name, dataIn, WRITE_SIZE/8);

	cout << WRITE_SIZE << endl;
	cout << "autoTime:" << autoTime << endl;
	cout << "diveTime:" << diveTime << endl;
	closeUSB();
}
