// TimePro.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/*#include <iostream>
#include <thread>
#include "time.h"

int main() {
	std::cout << "���õ�ʱ��Ϊ��" << std::endl;
	Time timer("123");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << timer.elapsed() << std::endl;
	timer.restart();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	timer.rlog("ʱ��");
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


	//��ȡʱ��Ƶ��
	LARGE_INTEGER m_liPerfFreq = { 0 };
	QueryPerformanceFrequency(&m_liPerfFreq);

	//��ȡ��ʼ����
	LARGE_INTEGER m_liPerfStart = { 0 };
	QueryPerformanceCounter(&m_liPerfStart);

	//���Դ����λ��
	for (int ix = 0; ix<100000; ix++) {
		cout << " ";
	}

	//��ȡ������
	LARGE_INTEGER liPerfNow = { 0 };
	QueryPerformanceCounter(&liPerfNow);

	//����ʱ��
	long long time = (((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000) / m_liPerfFreq.QuadPart);


	cout << time << endl;


	system("pause");
	return 0;
}*/

//Windowsϵͳ��time()��clock()��timeGetTime()��GetTickCount()��QueryPerformanceCounter()����ʱ by MoreWindows  
#include <stdio.h>  
#include <windows.h>  
#include <time.h> //time_t time()  clock_t clock()  
#include <Mmsystem.h>             //timeGetTime()  
#pragma comment(lib, "Winmm.lib")   //timeGetTime()  

int main1()
{
	//��time()����ʱ  ��  
	time_t timeBegin, timeEnd;
	timeBegin = time(NULL);
	Sleep(2000);
	timeEnd = time(NULL);
	printf("%ld\n", timeEnd - timeBegin);


	//��clock()����ʱ  ����  
	clock_t  clockBegin, clockEnd;
	clockBegin = clock();
	Sleep(801);
	clockEnd = clock();
	printf("%d\n", clockEnd - clockBegin);


	//��timeGetTime()����ʱ  ����  
	DWORD  dwBegin, dwEnd;
	dwBegin = timeGetTime();
	Sleep(802);
	dwEnd = timeGetTime();
	printf("%d\n", dwEnd - dwBegin);


	//��GetTickCount()����ʱ  ����  
	DWORD  dwGTCBegin, dwGTCEnd;
	dwGTCBegin = GetTickCount();
	Sleep(800);
	dwGTCEnd = GetTickCount();
	printf("%d\n", dwGTCEnd - dwGTCBegin);


	//��QueryPerformanceCounter()����ʱ  ΢��  
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
	printf("�����߾��ȼ�ʱ��Ƶ��%lf\n", dff);
	printf("��һ�μ�ʱ��ֵ%I64d �ڶ��μ�ʱ��ֵ%I64d ��ʱ����%I64d\n", c1, c2, c2 - c1);
	printf("��ʱ%lf����\n", (c2 - c1) * 1000 / dff);

	printf("By MoreWindows\n");

	system("pause");
	return 0;
}