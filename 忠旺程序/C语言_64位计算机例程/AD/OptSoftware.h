#pragma once
#include<fstream>
#include"FileIo.h"
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <WinUser.h>
#include <string.h>


using namespace std;
class OptSoftware
{
public:
	OptSoftware(char buf[], int length);
	~OptSoftware() {};

	char recvBuf[50];

	std::wstring StringToWString(const std::string& str);
	std::string WStringToString(const std::wstring &wstr);
	void run();
	
};

