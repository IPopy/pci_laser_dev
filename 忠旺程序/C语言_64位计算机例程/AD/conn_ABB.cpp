// conn_ABB.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <windows.h>
//#include <WinUser.h>
#include <iostream>
#include "Machine.h"
#include<fstream>
#include"FileIo.h"
#include <stdio.h>
#include "OptSoftware.h"
#include <TlHelp32.h>

using namespace std;

void mouse_left_click(HWND gameh, int x, int y)
{
	LPARAM lparam = MAKELPARAM(x, y); //x坐标，y坐标
	LRESULT result = ::SendMessage(gameh, WM_LBUTTONDOWN, VK_LBUTTON, lparam);
	LRESULT result1 = ::SendMessage(gameh, WM_LBUTTONUP, 0, lparam);
	//cout << "鼠标按下%d,弹起%d" << result, result1;
}
std::wstring StringToWString(const std::string& str)
{
	int num = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	wchar_t *wide = new wchar_t[num];
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wide, num);
	std::wstring w_str(wide);
	delete[] wide;
	return w_str;
}

int main() 
{
	//char *str_array[] = {"200","345","345" ,"345" };
	//FileIo fi;
	//fi.write("d://test.txt",str_array);

	Machine ma;
	ma.socket_server();


	/*
	wstring str_1 = L"ThorX6 - ";

	wstring str = StringToWString("100x");
	wstring str_2 = str.substr(0, str.length() - 1);

	wstring str_3 = L".Tx6";

	str_1.append(str_2);
	str_1.append(str_3);

	HWND hWnd = FindWindow(NULL, str_1.c_str());


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


		keybd_event((BYTE)('1'), 0, 0, 0);
		keybd_event((BYTE)('1'), 0, KEYEVENTF_KEYUP, 0);


keybd_event(VK_RETURN, 0, 0, 0);
keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

keybd_event(VK_RETURN, 0, 0, 0);
keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 150 * 65536 / 1024, 40 * 65536 / 768, 0, 0);
mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 210 * 65536 / 1024, 80 * 65536 / 768, 0, 0);
mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);*/
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
	/*
HWND hWndChild = FindWindowW(NULL, L"文本数据源");
SetForegroundWindow(hWndChild);
keybd_event(13, 0, 0, 0);
keybd_event(13, 0, KEYEVENTF_KEYUP, 0);

getchar();*/

	
	return 0;
}