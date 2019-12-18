#include "pch.h"
#include "menu.h"
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void HidCursor() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = 0;
	SetConsoleCursorInfo(handle, &CursorInfo);
}
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}
void setcolor(int fr, int fg, int fb, int fi, int br, int bg, int bb, int bi) {
	int val = 0;
	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);//实例化句柄
	val = (bi << 7) + (bb << 4) + (bg << 5) + (br << 6) + (fi << 3) + (fb << 0) + (fg << 1) + (fr << 2);
	SetConsoleTextAttribute(consolehwnd, val);//设置字体颜色
}

char getch2() {
	int input = 1;
	input = _getch();
	if (input == 224) {
		input = _getch();
	}
	return input;
}

int pnt_danxuan(menu* m, int size, int up) {
	int i;
	HidCursor();
	int input = -1, pos = up - 1, lst = up;
	//system("cls");
	for (i = 0; i < size; i++) {
		gotoxy(0, up + i);
		printf("( ) %s\n", m[i].name);
	}
	while (input = getch2()) {
		if (input == kbTAB || input == kbENTER) {
			if (pos == up - 1) {
				continue;
			}
			system("cls");
			return pos - up;
			break;
		}
		if (input == kbW && pos != 0 + up && pos != -1 + up) {
			pos--;
		}
		else if (input == kbS && pos != size - 1 + up) {
			pos++;
		}
		else continue;
		gotoxy(1, lst);
		printf(" ");
		gotoxy(1, pos);
		printf("*");
		lst = pos;
	}
	return 0;
}