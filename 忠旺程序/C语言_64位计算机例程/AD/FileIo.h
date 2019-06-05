#pragma once
#include <iostream> 
#include <fstream> 
#include <cstring>
#include <string>
#include <time.h>
#include "PciLaser.h"
#include <vector>

using namespace std;

class FileIo
{
public:
	FileIo() {};
	~FileIo() {};
	string getCurrentName();
	string getCurrentName(char name[]);

	template<class T>
	int length(T& arr);
	void write(string file_name, char *s_num[]);

	void write(string file_name, float f_num[], int size);
	void write(string file_name, PciLaser ce, int size);
	void read(string file_name);
	bool read(string file_name, float out_data[]);
	vector<string> split2(const string &str, const string &pattern);
};



