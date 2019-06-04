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
	OptSoftware() {};
	~OptSoftware() {};

	char recvBuf[50];

	std::wstring StringToWString(const std::string& str)
	{
		int num = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
		wchar_t *wide = new wchar_t[num];
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wide, num);
		std::wstring w_str(wide);
		delete[] wide;
		return w_str;
	}

	std::string WStringToString(const std::wstring &wstr)
	{
		std::string str;
		int nLen = (int)wstr.length();
		str.resize(nLen, ' ');
		int nResult = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wstr.c_str(), nLen, (LPSTR)str.c_str(), nLen, NULL, NULL);
		if (nResult == 0)
		{
			return "";
		}
		return str;
	}

	void run()
	{
		HWND hWnd;
		if (recvBuf[0] == 'x')
		{
			hWnd = FindWindow(NULL, L"ThorX6 - 无标题");
		}
		else
		{
			wstring str_1 = L"ThorX6 - ";

			wstring str = StringToWString(recvBuf);
			wstring str_2=str.substr(0, str.length() - 1);

			wstring str_3 = L".Tx6";

			str_1.append(str_2);
			str_1.append(str_3);
						
			hWnd = FindWindow(NULL, str_1.c_str());
		}
		if (IsIconic(hWnd))
		{
			cout << "目标程序处于最小化\n";
			ShowWindow(hWnd, SW_MAXIMIZE);

		}

		SetForegroundWindow(hWnd);

		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 20 * 65536 / 1024, 27 * 65536 / 768, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

		keybd_event(VK_DOWN, 0, 0, 0);
		keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);

		keybd_event(VK_DOWN, 0, 0, 0);

		keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);

		keybd_event(VK_RETURN, 0, 0, 0);
		keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

		int length = (sizeof(recvBuf)/sizeof(recvBuf[0]));

		cout << length << endl;
		for (size_t i = 0; i <length; i++)
		{
			if (recvBuf[i] == 'x')
			{
				break;
			}
			else
			{				
				keybd_event((BYTE)(recvBuf[i]), 0, 0, 0);
				keybd_event((BYTE)(recvBuf[i]), 0, KEYEVENTF_KEYUP, 0);
			}

		}
		
		keybd_event(VK_RETURN, 0, 0, 0);
		keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

		keybd_event(VK_RETURN, 0, 0, 0);
		keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 150 * 65536 / 1024, 40 * 65536 / 768, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 210 * 65536 / 1024, 80 * 65536 / 768, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		//char* aa = "A2";
		//SendMessage()
		//发送填写的路径
		//SendMessage(h3, WM_SETTEXT, 42, (LPARAM)v_path);
		//long i_temp1 = ::SendMessage(hwnd_text, WM_SETTEXT, 0, LPARAM(aa));


		//keybd_event(VK_RETURN, 0, 0, 0);
		//keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
		//mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 20 * 65536 / 1024, 130 * 65536 / 768, 0, 0);
		//mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 20 * 65536 / 1024, 133 * 65536 / 768, 0, 0);
		//mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);


		//POINT last_p;

		//GetCursorPos(&last_p);
		//cout << last_p.x << endl;
		//cout << last_p.y << endl;
		//SendMessage(hWnd, WM_LBUTTONDOWN, 0, MAKELONG(last_p.x, last_p.y));
		//SendMessage(hWnd, WM_LBUTTONUP, 0, MAKELONG(last_p.x, last_p.y));
		//SendMessage(hWnd, WM_LBUTTONUP, 0, MAKELONG(0, 0));

		//keybd_event(17 | 79, 0, KEYEVENTF_KEYUP, 0);

		/*mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 650 * 65536 / 1024, 100 * 65536 / 768, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 650 * 65536 / 1024, 100 * 65536 / 768, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 650 * 65536 / 1024, 100 * 65536 / 768, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 650 * 65536 / 1024, 100 * 65536 / 768, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		*/

		HWND hWndChild = FindWindowW(NULL, L"文本数据源");
		SetForegroundWindow(hWndChild);
		keybd_event(13, 0, 0, 0);
		keybd_event(13, 0, KEYEVENTF_KEYUP, 0);

		getchar();
	}
};

