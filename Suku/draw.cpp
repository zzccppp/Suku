#include "pch.h"
#include "draw.h"
#include "init.h"
#include <graphics.h>


void dfs_draw(int suku[9][9], int count, int *n)
{
	if (count == 81)
	{
		repaint_board();
		draw_suku(suku);
		(*n)++;
		return;
	}
	int i = count / 9, j = count % 9;
	if (suku[i][j] != 0)
	{
		dfs_draw(suku, count + 1, n);
		return;
	}
	for (int k = 0; k < 9; k++)
	{
		suku[i][j]++;
		if (*n == 0)
		{
			//Sleep(1);
			repaint_cell(suku, i, j);
		}
		if (isRepeat(suku, i, j))
		{
			if (*n == 0)
			{
				//Sleep(1);
				repaint_cell(suku, i, j);
			}
			dfs_draw(suku, count + 1, n);
		}
	}
	suku[i][j] = 0;
	return;
}

void draw_suku(int suku[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if ((i + j) % 2 == 0)
			{
				RECT r = { j * BLOCKS_WIDE,i * BLOCKS_WIDE,j * BLOCKS_WIDE + BLOCKS_WIDE,i * BLOCKS_WIDE + BLOCKS_WIDE };
				if (suku[i][j] != 0)
				{
					drawtext((char)(suku[i][j] + '0'), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
			}
			else
			{
				RECT r = { j * BLOCKS_WIDE,i * BLOCKS_WIDE,j * BLOCKS_WIDE + BLOCKS_WIDE,i * BLOCKS_WIDE + BLOCKS_WIDE };
				if (suku[i][j] != 0)
				{
					drawtext((char)(suku[i][j] + '0'), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
			}
		}
	}
}

void init_graph()
{
	initgraph(9 * BLOCKS_WIDE, 9 * BLOCKS_WIDE);
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = BLOCKS_WIDE * 3 / 4;
	settextcolor(BLACK);
	_tcscpy(f.lfFaceName, _T("ºÚÌå"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if ((i + j) % 2 == 0)
			{
				setfillcolor(RGB(135, 206, 250));
				solidrectangle(j * BLOCKS_WIDE, i * BLOCKS_WIDE, j * BLOCKS_WIDE + BLOCKS_WIDE, i * BLOCKS_WIDE + BLOCKS_WIDE);
			}
			else
			{
				setfillcolor(RGB(255, 250, 250));
				solidrectangle(j * BLOCKS_WIDE, i * BLOCKS_WIDE, j * BLOCKS_WIDE + BLOCKS_WIDE, i * BLOCKS_WIDE + BLOCKS_WIDE);
			}
		}
	}
}

void repaint_board()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if ((i + j) % 2 == 0)
			{
				setfillcolor(RGB(135, 206, 250));
				solidrectangle(j * BLOCKS_WIDE, i * BLOCKS_WIDE, j * BLOCKS_WIDE + BLOCKS_WIDE, i * BLOCKS_WIDE + BLOCKS_WIDE);
			}
			else
			{
				setfillcolor(RGB(255, 250, 250));
				solidrectangle(j * BLOCKS_WIDE, i * BLOCKS_WIDE, j * BLOCKS_WIDE + BLOCKS_WIDE, i * BLOCKS_WIDE + BLOCKS_WIDE);
			}
		}
	}
}

void repaint_cell(int suku[9][9], int i, int j)
{
	if ((i + j) % 2 == 0)
	{
		setfillcolor(RGB(135, 206, 250));
		solidrectangle(j * BLOCKS_WIDE, i * BLOCKS_WIDE, j * BLOCKS_WIDE + BLOCKS_WIDE, i * BLOCKS_WIDE + BLOCKS_WIDE);
	}
	else
	{
		setfillcolor(RGB(255, 250, 250));
		solidrectangle(j * BLOCKS_WIDE, i * BLOCKS_WIDE, j * BLOCKS_WIDE + BLOCKS_WIDE, i * BLOCKS_WIDE + BLOCKS_WIDE);
	}
	RECT r = { j * BLOCKS_WIDE,i * BLOCKS_WIDE,j * BLOCKS_WIDE + BLOCKS_WIDE,i * BLOCKS_WIDE + BLOCKS_WIDE };
	if (suku[i][j] != 0)
	{
		drawtext((char)(suku[i][j] + '0'), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}