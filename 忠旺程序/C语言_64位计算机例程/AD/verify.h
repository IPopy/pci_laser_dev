/*
 * 功能：验证板卡两种获取数据的方式，所用的时间
 * 结论：时间差不足 10ms，可以忽略，分开来所用时间更短
 * Read_AdBuf() 调用后会将缓存区清空
 */

#pragma once
#include <time.h>


class Verify
{
public:
	Verify() {
		startTime = 0;
		stopTime = 0;
		getBSTime = 0;
		readBTime = 0;
		autoTime = 0;
		diveTime = 0;
	};
	~Verify() {};
	void test();

	clock_t startTime;
	clock_t stopTime;
	clock_t getBSTime;
	clock_t readBTime;

	clock_t diveTime;
	clock_t autoTime;
};

