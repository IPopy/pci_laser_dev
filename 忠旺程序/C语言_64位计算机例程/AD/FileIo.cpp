#include "stdafx.h"
#include "FileIo.h"

string FileIo::getCurrentName()
{
	time_t currtime = time(NULL);
	tm* p = localtime(&currtime);
	char filename[100] = { 0 };
	sprintf(filename, "%d%02d%02d%02d%02d%02d.txt", p->tm_year + 1900, p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
	return filename;
}
string FileIo::getCurrentName(char name[])
{
	time_t currtime = time(NULL);
	tm* p = localtime(&currtime);
	char filename[100] = { 0 };
	sprintf(filename, "%d%02d%02d%02d%02d%02d_%s.txt", p->tm_year + 1900, p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, name);
	return filename;
}

template<class T>

int FileIo::length(T& arr)
{
	//cout << sizeof(arr[0]) << endl;
	//cout << sizeof(arr) << endl;
	return sizeof(arr) / sizeof(arr[0]);
}

void FileIo::write(string file_name, char *s_num[])
{
	// *************************写txt文件*******************************

	//ofstream OutFile;??????????? //实例一个写文件对象

	//OutFile.open("Test1.xlsx");???? //创建一个Test.txt文本，并且打开Test.txt文件

	ofstream OutFile(file_name);

	//string str_array[10];
	//memcpy(str_array, s_num, sizeof(s_num));
	for (int i = 0; i < length(s_num); i++)
	{
		OutFile << s_num[i] << endl;
	}
	OutFile.close();

}
void FileIo::write(string file_name, float f_num[], int size)
{
	ofstream OutFile(file_name, ofstream::app);


	for (int i = 0; i < size; ++i)
	{
		OutFile << f_num[i] << "\t";
	}
	OutFile << endl;
	OutFile.close();
}
void FileIo::write(string file_name, Ceju ce, int size)
{
	ofstream OutFile(file_name, ofstream::app);

	OutFile << "Begin:" << ce.begin << "\tTime: " << ce.time << "\t" << ce.useful << endl;
	for (int i = 0; i < size; ++i)
	{
		char height[10];
		sprintf(height, "%.5f", ce.height[i]);
		OutFile << height << "\t";
		//OutFile << ce.height[i] << "\t";
		if (i % 10 == 0)
		{
			OutFile << endl;
		}
	}
	OutFile << endl << endl << endl;
	OutFile.close();
}
void FileIo::read(string file_name)
{
	// *************************读txt文件*******************************

	ifstream readFile(file_name);

	char temp[1024] = { 0 };

	readFile >> temp;

	//readFile.getline(temp, 8， 0);?? //可以输出空格，遇到delim符号才截止。 最后一个参数0表示文本框遇到空字符（ASCLL码为32，文本框不可能有空字符）截止符。不加第三个参数0时，表示'\n'为截止符('\n'也是换行符)。如图4所示

	cout << temp << endl;

	readFile.close();
}
vector<string> dataaaa;
vector<string>::iterator it;
bool FileIo::read(string file_name, float out_data[])
{
	// *************************读txt文件*******************************
	size_t num = 0;
	ifstream readFile(file_name);

	char temp[1024] = { 0 };
	float f = 0;
	while (!readFile.eof())
	{
		readFile.getline(temp, 1024);
		string line(temp);

		// 判断第一个字符是否是字母或空，
		if (temp[0] == 'B' )
			continue;

		// 将一行数据分割
		dataaaa = split2(line, "\t");
	
		it = dataaaa.begin();
		for (; it != dataaaa.end(); it++)
		{
			const char *ch = (*it).c_str();

			//f = atof(ch);
			out_data[num] = f;
			++num;
		}
		dataaaa.clear();
		//readFile.getline(temp, 8， 0);?? //可以输出空格，遇到delim符号才截止。 最后一个参数0表示文本框遇到空字符（ASCLL码为32，文本框不可能有空字符）截止符。不加第三个参数0时，表示'\n'为截止符('\n'也是换行符)。如图4所示

	

	}
	readFile.close();
	return true;
}
vector<string> res;
vector<string> FileIo::split2(const string &str, const string &pattern)
{
	res.clear();
	if (str == "")
		return res;
	string strs = str + pattern;
	size_t pos = str.find(pattern);
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);

		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(pattern);
	}

	return res;

}