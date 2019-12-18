#include "pch.h"
#include "play.h"
#include "draw.h"
#include "init.h"
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

void manual_play(int dif)
{
	init_graph();
	repaint_board();
	int suku[9][9];
	initAns(suku);
	int ans[9][9];
	for (int i = 0; i < 9; i++) //save Answer
	{
		for (int j = 0; j < 9; j++)
		{
			ans[i][j] = suku[i][j];
		}
	}
	initEasyQuestion(suku, dif);
	int question[9][9];
	for (int i = 0; i < 9; i++) //save question
	{
		for (int j = 0; j < 9; j++)
		{
			question[i][j] = suku[i][j];
		}
	}
	draw_suku(suku); // ready to start play
	int isWin = 0;
	int posx = 0, posy = 0;
	while (!isWin)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			FlushMouseMsgBuffer();
			int j = m.x / BLOCKS_WIDE;
			int i = m.y / BLOCKS_WIDE;
			if (question[i][j] == 0)
			{
				setfillcolor(RGB(238, 130, 238));
				solidrectangle(j * BLOCKS_WIDE, i * BLOCKS_WIDE, j * BLOCKS_WIDE + BLOCKS_WIDE, i * BLOCKS_WIDE + BLOCKS_WIDE);
				PlaySound(TEXT("click_1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				Sleep(240);
				PlaySound(NULL, NULL, SND_FILENAME);

				int num = _getch();
				if (num >= '0' && num <= '9')
				{
					suku[i][j] = num - '0';
					repaint_cell(suku, i, j);
					if(isCorrect(ans,suku))
					{
						return;
					}
				}
				else
				{
					repaint_cell(suku, i, j);
				}
			}
		}
		else
		{
			FlushMouseMsgBuffer();
			if (_kbhit())
			{
				_getch();
			}
		}
	}
}

void automatic_play(int dif)
{
	init_graph();
	repaint_board();
	int suku[9][9];
	initAns(suku);
	initEasyQuestion(suku, dif);
	draw_suku(suku);
	_getch();
	int n = 0;
	dfs_draw(suku, 0, &n);
	//_getch();
	//closegraph();
}

void dfs(int suku[9][9], int count)
{
	if (count == 81)
	{
		repaint_board();
		draw_suku(suku);
		return;
	}
	int i = count / 9, j = count % 9;
	if (suku[i][j] != 0)
	{
		dfs(suku, count + 1);
		return;
	}
	for (int k = 0; k < 9; k++)
	{
		suku[i][j]++;
		if (isRepeat(suku, i, j))
		{
			dfs(suku, count + 1);
		}
	}
	suku[i][j] = 0;
	return;
}

int isCorrect(int ans[9][9], int test[9][9])
{
	for (int i = 0; i < 9; i++) //save Answer
	{
		for (int j = 0; j < 9; j++)
		{
			if (ans[i][j] != test[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}