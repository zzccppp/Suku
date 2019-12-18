#pragma once

#define kbTAB 9
#define kbENTER 13
#define kbW 72
#define kbA 75
#define kbS 80
#define kbD 77

typedef struct MENU {
	char name[260];
} menu;

void HidCursor();

void gotoxy(int x, int y);

void setcolor(int fr, int fg, int fb, int fi, int br, int bg, int bb, int bi);

char getch2();

int pnt_danxuan(menu* m, int size, int up);