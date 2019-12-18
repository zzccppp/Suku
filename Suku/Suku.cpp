// Suku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "init.h"
#include "menu.h"
#include "draw.h"
#include "play.h"

#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>


int main()
{
	srand(time(0));
	printf("欢迎游玩本数独游戏！！！\n");
	printf("使用方向键移动菜单。\n");
	printf("祝游玩愉快(按任何键继续...)\n");
	_getch();
start:;
	int chose = 0;
	menu *m = (menu*)malloc(sizeof(menu) * 5);
	strcpy(m[0].name, "1. 开始游戏");
	strcpy(m[1].name, "2. 自动生成并求解");
	strcpy(m[2].name, "3. 帮助(用方向键选择菜单)");
	strcpy(m[3].name, "4. 关于");
	strcpy(m[4].name, "5. 退出");
	system("cls");
	chose = pnt_danxuan(m, 5, 0);
	if (chose == 0)
	{
		menu *sub = (menu*)malloc(sizeof(menu) * 4);
		strcpy(sub[0].name, "1. 简单");
		strcpy(sub[1].name, "2. 中等");
		strcpy(sub[2].name, "3. 困难");
		strcpy(sub[3].name, "4. 返回");
		system("cls");
		int cc = pnt_danxuan(sub, 4, 0);
		if (cc == 3)
		{
			free(sub);
			goto start;
		} else
		{
			int difficulty = cc + 1;
			
			time_t t_start = time(0);
			manual_play(difficulty);
			time_t t_end = time(0);
			
			//print you win!!!
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 30;
			settextcolor(RED);
			_tcscpy(f.lfFaceName, _T("黑体"));
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			RECT r = { 0,4 * BLOCKS_WIDE,9 * BLOCKS_WIDE, 9 * BLOCKS_WIDE };
			wchar_t buf[1024];
			swprintf_s(buf, L"You Win!!\nYou took %lld secs.\nPress any key continue...", (t_end - t_start));
			drawtext(buf, &r, DT_CENTER | DT_VCENTER | DT_WORDBREAK);
			PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			Sleep(5500);
			PlaySound(NULL, NULL, SND_FILENAME);
			_getch();
			closegraph();
			free(sub);
			goto start;
			
		}
	}
	else if (chose == 1)
	{
		menu *sub = (menu*)malloc(sizeof(menu) * 4);
		strcpy(sub[0].name, "1. 简单(进入后待初始化后按任意键开始求解)");
		strcpy(sub[1].name, "2. 中等");
		strcpy(sub[2].name, "3. 困难(初始化时间可能较长)");
		strcpy(sub[3].name, "4. 返回");
		system("cls");
		int cc = pnt_danxuan(sub, 4, 0);
		if(cc == 3)
		{
			free(sub);
			goto start;
		} else
		{
			int difficulty = cc + 1;

			time_t t_start = time(0);
			automatic_play(difficulty);
			time_t t_end = time(0);
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 30;
			settextcolor(RED);
			_tcscpy(f.lfFaceName, _T( "黑体"));
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			RECT r = { 0,4*BLOCKS_WIDE,9 * BLOCKS_WIDE, 9 * BLOCKS_WIDE };
			wchar_t buf[1024];
			swprintf_s(buf, L"You Win!!\nYou took %lld secs.\nPress any key continue...",(t_end - t_start));
			drawtext(buf, &r, DT_CENTER | DT_VCENTER | DT_WORDBREAK);
			PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			Sleep(5500);
			PlaySound(NULL, NULL, SND_FILENAME);
			_getch();
			closegraph();
			
			free(sub);
			goto start;
		}
	}
	else if (chose == 2)
	{
		printf("菜单中请使用键盘操作，游戏中请使用鼠标点选单元后再用键盘输入数字。");
		_getch();
		goto start;
	}
	else if (chose == 3)
	{
		printf("Author:ZZDirty\n\nFor C program language lesson homework.\n\nPress any key to continue.\n");
		_getch();
		goto start;
	}
	else if (chose == 4)
	{
		//do nothing
	}
	free(m);
	return 0;
}
