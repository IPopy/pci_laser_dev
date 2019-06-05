#pragma once
#include "SocketTcp.h"


class ZhongWangDev : SocketTcp
{

public:
	ZhongWangDev():SocketTcp(){};
	~ZhongWangDev() {};
	void monitor();
	// enum CHOISE choise;

public:
	enum CHOISE
	{
		ROBOTERROR = 0,
		OPTSOFTWARE = 1,
		PCILASER = 2,		
	}choise;

	
};