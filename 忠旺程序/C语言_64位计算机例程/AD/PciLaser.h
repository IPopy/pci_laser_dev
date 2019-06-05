#pragma once
#include "time.h"

#define Nchannel  8
#define NX  128

//#define data_num  NX*Nchannel;


#define HIGH_UP 2.3
#define HIGH_DOWN 2.8
#define LOWER 1.5
#define OUT_RANGE 4.99

class PciLaser
{
public:
	PciLaser(char buf[], int length);
	PciLaser() {};
	~PciLaser();

	char recvBuf[50];

	int getOriginData();
	float getRealTime(float speed);
	void printtttt();
private:
	int getDistance();	// 这个用的很不准，等待 wtc 的建模
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
