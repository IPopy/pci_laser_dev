// TimePro.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*#include <iostream>
#include <thread>
#include "time.h"

int main() {
	std::cout << "所用的时间为：" << std::endl;
	Time timer("123");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << timer.elapsed() << std::endl;
	timer.restart();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	timer.rlog("时间");
	return 0;
}*/

/*#include<iostream>
#include<windows.h>
using namespace std;

int main(void)
{


	system("color F0");


	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(10);


	//获取时钟频率
	LARGE_INTEGER m_liPerfFreq = { 0 };
	QueryPerformanceFrequency(&m_liPerfFreq);

	//获取初始计数
	LARGE_INTEGER m_liPerfStart = { 0 };
	QueryPerformanceCounter(&m_liPerfStart);

	//测试代码的位置
	for (int ix = 0; ix<100000; ix++) {
		cout << " ";
	}

	//获取最后计数
	LARGE_INTEGER liPerfNow = { 0 };
	QueryPerformanceCounter(&liPerfNow);

	//计算时间
	long long time = (((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000) / m_liPerfFreq.QuadPart);


	cout << time << endl;


	system("pause");
	return 0;
}*/

//Windows系统下time()，clock()，timeGetTime()，GetTickCount()，QueryPerformanceCounter()来计时 by MoreWindows  
#include <stdio.h>  
#include <windows.h>  
#include <time.h> //time_t time()  clock_t clock()  
#include <Mmsystem.h>             //timeGetTime()  
#pragma comment(lib, "Winmm.lib")   //timeGetTime()  

int main1()
{
	//用time()来计时  秒  
	time_t timeBegin, timeEnd;
	timeBegin = time(NULL);
	Sleep(2000);
	timeEnd = time(NULL);
	printf("%ld\n", timeEnd - timeBegin);


	//用clock()来计时  毫秒  
	clock_t  clockBegin, clockEnd;
	clockBegin = clock();
	Sleep(801);
	clockEnd = clock();
	printf("%d\n", clockEnd - clockBegin);


	//用timeGetTime()来计时  毫秒  
	DWORD  dwBegin, dwEnd;
	dwBegin = timeGetTime();
	Sleep(802);
	dwEnd = timeGetTime();
	printf("%d\n", dwEnd - dwBegin);


	//用GetTickCount()来计时  毫秒  
	DWORD  dwGTCBegin, dwGTCEnd;
	dwGTCBegin = GetTickCount();
	Sleep(800);
	dwGTCEnd = GetTickCount();
	printf("%d\n", dwGTCEnd - dwGTCBegin);


	//用QueryPerformanceCounter()来计时  微秒  
	LARGE_INTEGER  large_interger;
	double dff;
	__int64  c1, c2;
	QueryPerformanceFrequency(&large_interger);
	dff = large_interger.QuadPart;
	QueryPerformanceCounter(&large_interger);
	c1 = large_interger.QuadPart;
	Sleep(800);
	QueryPerformanceCounter(&large_interger);
	c2 = large_interger.QuadPart;
	printf("本机高精度计时器频率%lf\n", dff);
	printf("第一次计时器值%I64d 第二次计时器值%I64d 计时器差%I64d\n", c1, c2, c2 - c1);
	printf("计时%lf毫秒\n", (c2 - c1) * 1000 / dff);

	printf("By MoreWindows\n");

	system("pause");
	return 0;
}