#include "pch.h"
#include "init.h"

#include <stdlib.h>
#include <time.h>

void initAns(int suku[9][9])
{
	int seednum = rand() % 4; // 种子矩阵编号
	int seed[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			seed[i][j] = seed_suku[seednum][i][j];  //复制种子矩阵
		}
	}
	int switchTimes = 0;
	while (switchTimes < 3)
	{
		switchTimes = rand() % 10; //随机交换次数
	}
	for (int k = 0; k < switchTimes; k++)
	{
		int temp[9][9];
		if (rand() % 2 == 0)//列变换
		{
			sukuMultiply(seed, trans[rand() % 9], temp);
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					seed[i][j] = temp[i][j];  //保存运算结果
				}
			}
		}
		else // 行变换
		{
			sukuMultiply(trans[rand() % 9], seed, temp);
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					seed[i][j] = temp[i][j];  //保存运算结果
				}
			}
		}
	}
	switchTimes = 0;
	while (switchTimes < 2)
	{
		switchTimes = rand() % 5; //随机交换次数
	}
	for (int k = 0; k < switchTimes; k++) // 交换两个数
	{
		int base1 = rand() % 9;
		while (base1 == 0) { base1 = rand() % 9; }
		int base2 = rand() % 9;
		while (base2 == 0 || base2 == base1)
		{
			base2 = rand() % 9;
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (seed[i][j] == base1)
				{
					seed[i][j] = base2;
				}
				else if (seed[i][j] == base2)
				{
					seed[i][j] = base1;
				}
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			suku[i][j] = seed[i][j];  //复制种子矩阵
		}
	}
}

void sukuMultiply(int r[9][9], int l[9][9], int result[9][9]) //封装乘法
{
	Multi(r[0], l[0], result[0], 9, 9, 9, 9);
}

void Multi(int * left, int * right, int * result, int f1, int f2, int s1, int s2) // 矩阵乘法，用于交换数独的两行或两列
{
	//int a[f1][f2], b[s1][s2], c[f1][s2];
	//a[i][j]==a[i*f2+j]
	//由矩阵相乘，要求f2=s1，以下用f2
	for (int i = 0; i < f1; i++)    //i表示第i行
	{
		for (int j = 0; j < s2; j++) //j表示第j列
		{
			result[i*f2 + j] = 0;        //在这里 result[i][j] = result[i*f2+j];
			for (int p = 0; p < f2; p++)
			{
				result[i*f2 + j] += left[i*f2 + p] * right[p*f2 + j];
			}
		}
	}
}

/**
 * @author ZZDirty
 *
 * difficult:
 * 1 -> easy
 * 2 -> normal
 * 3 -> hard
 *
 */
void initQuestion(int suku[9][9], int difficult)
{
	if (difficult != 3)
	{
		initEasyQuestion(suku, difficult);
		return;
	}
	else
	{
		initEasyQuestion(suku, 2);
		int delCell = 3;
		do
		{
			int temp[9][9];
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					temp[i][j] = suku[i][j];  //复制矩阵
				}
			}
			while (delCell--) // 随机删除元素
			{
				int x = rand() % 9;
				int y = rand() % 9;
				while (temp[x][y] == 0)
				{
					x = rand() % 9;
					y = rand() % 9;
				}
				temp[x][y] = 0;
			}
			int n = 0;
			isOnlySolve(temp, 0, &n);
			if (n == 1)
			{
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						suku[i][j] = temp[i][j];  //复制矩阵
					}
				}
				return;
			}
		} while (1);
	}
}

void initEasyQuestion(int suku[9][9], int difficult)
{
	do {
		int temp[9][9];
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				temp[i][j] = suku[i][j];  //复制矩阵
			}
		}
		int delCell;
		if (difficult == 1)
		{
			delCell = 81 - (rand() % 5 + 38);
		}
		else if (difficult == 2)
		{
			delCell = 81 - (rand() % 5 + 33);
		}
		else
		{
			delCell = 81 - (rand() % 5 + 27);
		}
		while (delCell--) // 随机删除元素
		{
			int x = rand() % 9;
			int y = rand() % 9;
			while (temp[x][y] == 0)
			{
				x = rand() % 9;
				y = rand() % 9;
			}
			temp[x][y] = 0;
		}
		int n = 0;
		isOnlySolve(temp, 0, &n);
		if (n == 1)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					suku[i][j] = temp[i][j];  //复制矩阵
				}
			}
			return;
		}
	} while (1);
}

int isRepeat(int suku[9][9], int i, int j) {
	int num = suku[i][j];
	int start[9] = { 0,0,0,3,3,3,6,6,6 };
	int p, q;
	for (p = 0; p < 9; p++) {
		if ((p != i && suku[p][j] == num) || (p != j && suku[i][p] == num)) {
			return 0; // false
		}
	}
	for (p = start[i]; p < start[i] + 3; p++) {
		for (q = start[j]; q < start[j] + 3; q++) {
			if ((p != i || q != j) && suku[p][q] == num) {
				return 0;//false
			}
		}
	}
	return 1;//pass
}

void dfs_solves_count(int suku[9][9], int count, int *n)
{
	if (count == 81)
	{
		(*n)++;
		return;
	}
	int i = count / 9, j = count % 9;
	if (suku[i][j] != 0)
	{
		dfs_solves_count(suku, count + 1, n);
		return;
	}
	for (int k = 0; k < 9; k++)
	{
		suku[i][j]++;
		if (isRepeat(suku, i, j))
		{
			dfs_solves_count(suku, count + 1, n);
		}
	}
	suku[i][j] = 0;
	return;
}

void isOnlySolve(int suku[9][9], int count, int *n)
{
	if (count == 81)
	{
		(*n)++;
		return;
	}
	int i = count / 9, j = count % 9;
	if (suku[i][j] != 0)
	{
		if (*n <= 1)
		{
			isOnlySolve(suku, count + 1, n);
			return;
		}
		else
		{
			return;
		}
	}
	for (int k = 0; k < 9; k++)
	{
		if (*n <= 1)
		{
			suku[i][j]++;
			if (isRepeat(suku, i, j))
			{
				isOnlySolve(suku, count + 1, n);
			}
		}
		else
		{
			return;
		}
	}
	suku[i][j] = 0;
	return;
}