#include "stdafx.h"
#include "PciLaser.h"
#include <iostream>
#include "FileIo.h"
#include <windows.h>

#pragma comment(lib,"Usb_Daq_V52_Dll.lib")
#include   "Usb_Daq_V52_Dll.h"


#define JISUAN_TIME 5000
PciLaser ceju[1000];
using std::cout;
using std::endl;


PciLaser::PciLaser(char buf[], int length)
{
	useful = false;
	ave = 0;
	usefulCount = 0;

	if (length < 0)
		return;
	for (int i = 0; i < length; ++i)
	{
		if (buf[i] == 'x')
		{
			recvBuf[i] = 'x';
			break;
		}
		else
		{
			recvBuf[i] = buf[i];
		}
	}
};
PciLaser::~PciLaser()
{

}

int PciLaser::getInfomation()
{
	
	int device_num = 10;
	int a = 0;

	// for (int i = 0; i < 1000000; i++) {}
	if (openUSB() != 0)
	{
		return -1;
	}

	//cout << "after usb after usb openafter usb open after usb open " << endl;
	for (int i = 0; i < 10000; i++) {}
	

	int data_num = NX*Nchannel;
	
	int ii = 0;

	clock_t start, end;
	start = clock();
	end = start;
	float dataIn[NX*Nchannel];
	// 一秒内采集的点
	while (end - start<JISUAN_TIME)
	{

		clock_t clockBegin, clockEnd;
		clockBegin = clock();
		ceju[ii].begin = clockBegin;
		if (ad_continu(0, 0, 0, 20000, 0, 0, 0, 0, data_num, dataIn) == -1)
			return -1;
		clockEnd = clock();
		ceju[ii].time = clockEnd - clockBegin;

		int t = 0;
		for (int i = 0; i < data_num; i += 8)
		{
			ceju[ii].height[t] = dataIn[i];
			
			//if (ceju[ii].height[t] > LOWER || ceju[ii].height[t] < HIGH)
			if (ceju[ii].height[t] > OUT_RANGE)
			{
				//ceju[ii].useful = false;
				ceju[ii].height[t] = -1;
			}
			else
			{
				ceju[ii].useful = true;
				ceju[ii].usefulCount++;
			}
			t++;
		}
		end = clock();
		ii++;
	}


	//ttttt();
	AD_continu_stop(0);

	closeUSB();
}

// 根据速度 返回距离
float PciLaser::getRealTime(float speed)
{
	clock_t startTime = clock();
	float distance = -1;
	if (openUSB() != 0)
	{
		return -1;
	}

	int data_num = NX*Nchannel;

	int ii = 0;

	clock_t start, end;
	start = clock();
	end = start;
	float dataIn[NX*Nchannel];
	// JISUAN_TIME 内采集的点
	while (end - start<JISUAN_TIME)
	{
		clock_t clockBegin, clockEnd;
		clockBegin = clock();
		ceju[ii].begin = clockBegin;
		if (ad_continu(0, 0, 0, 20000, 0, 0, 0, 0, data_num, dataIn) == -1)
		{
			closeUSB();
			return -1;
		}
			clockEnd = clock();
		ceju[ii].time = clockEnd - clockBegin;

		int t = 0;
		for (int i = 0; i < data_num; i += 8)
		{
			ceju[ii].height[t] = dataIn[i];

			if (ceju[ii].height[t] > OUT_RANGE)
			{
				ceju[ii].height[t] = -1;
			}

			if (ceju[ii].height[t] < HIGH_DOWN || ceju[ii].height[t] > HIGH_UP)
				ceju[ii].usefulCount++;

			

			++t;

			if (ceju[ii].usefulCount > 30)
			{
				distance = (ceju[ii].begin - startTime) * speed;

				AD_continu_stop(0);
				closeUSB();

				return distance;
			}
		}
		end = clock();
		ii++;
	}

	AD_continu_stop(0);
	closeUSB();

	return distance;
}

void PciLaser::printtttt()
{
	FileIo fi;
	string file_name = fi.getCurrentName();
	for (int i = 0; i < 100; i++)
	{
		//if (ceju[i].useful == true)
		//{
		//	fi.write(file_name, ceju[i], NX);
		//}
		fi.write(file_name, ceju[i], NX);
	}
}

int PciLaser::findSingleCGQ(float data[], int size)
{
	int len = sizeof(data);
	int flen = sizeof(float);
	if (sizeof(data)/ sizeof(float) <  8)
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
		fangcha[j] = (ave - data[j]) * (ave - data[j]);
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
int PciLaser::getDistance()
{
	if (openUSB() != 0)
	{
		return -1;
	}

	for (int i = 0; i < 10000; i++) {}

	// 开启连续模拟
	if (ad_continu_conf(0, 0, 0, 20000, 0, 0, 0, 0) == -1)
		return -1;

	int data_num = NX*Nchannel * 2;
	int ii = 0;

	clock_t start, end;
	start = clock();
	end = start;

	float dataIn[NX*Nchannel];
	// 一秒内采集的点
	while (end - start < JISUAN_TIME)
	{
		int size = Get_AdBuf_Size(0);
		if (size < 1024 * 8)
		{
			Sleep(1);
			end = clock();
			continue;
		}
		else
		{
			end = clock();
		}

		// 准备将时间写入
		ceju[ii].time = end;
		int sum = Read_AdBuf(0, dataIn, size);

		int i = findSingleCGQ(dataIn, 8);

		int t = 0;
		for (; i < size; i += 8)
		{
			if (dataIn[i] < LOWER || dataIn[i] > HIGH_UP)
			{
				ceju[ii].height[t] = dataIn[i];

				if (ceju[ii].height[t] > LOWER || ceju[ii].height[t] < HIGH_UP)
				{
					//ceju[ii].useful = false;
					ceju[ii].height[t] = 0;
				}
				else
				{
					ceju[ii].useful = true;
					ceju[ii].usefulCount++;
				}
			}

			t++;
		}
		end = clock();
		ii++;
	}

	AD_continu_stop(0);

	closeUSB();
}