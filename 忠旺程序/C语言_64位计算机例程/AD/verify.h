/*
 * ���ܣ���֤�忨���ֻ�ȡ���ݵķ�ʽ�����õ�ʱ��
 * ���ۣ�ʱ���� 10ms�����Ժ��ԣ��ֿ�������ʱ�����
 * Read_AdBuf() ���ú�Ὣ���������
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

