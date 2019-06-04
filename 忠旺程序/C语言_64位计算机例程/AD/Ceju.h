#pragma once
#include "time.h"

#define Nchannel  8
#define NX  128

//#define data_num  NX*Nchannel;


#define HIGH_UP 2.3
#define HIGH_DOWN 2.8
#define LOWER 1.5
#define OUT_RANGE 4.99

class Ceju
{
public:
	Ceju() 
	{
		useful = false;
		ave = 0;
		usefulCount = 0;
	};
	~Ceju() {};

	int getInfomation();
	float getInfomation(float speed, clock_t startTime);
	void verify();
	void printtttt();
private:
	int getInfomation2();	// 这个用的很不准
	int findSingleCGQ(float data[], int size);


public:
	clock_t time;
	clock_t begin;
	float height[NX];
	bool useful;
private:
	float ave;
	int usefulCount;
};
