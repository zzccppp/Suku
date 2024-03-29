﻿#pragma once

void initAns(int suku[9][9]);

void sukuMultiply(int r[9][9], int l[9][9], int result[9][9]);

void Multi(int * left, int * right, int * result, int f1, int f2, int s1, int s2);

static int seed_suku[4][9][9] = {
			{ { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 4, 5, 6, 7, 8, 9, 1, 2, 3 },
					{ 7, 8, 9, 1, 2, 3, 4, 5, 6 },
					{ 2, 1, 4, 3, 6, 5, 8, 9, 7 },
					{ 3, 6, 5, 8, 9, 7, 2, 1, 4 },
					{ 8, 9, 7, 2, 1, 4, 3, 6, 5 },
					{ 5, 3, 1, 6, 4, 2, 9, 7, 8 },
					{ 6, 4, 2, 9, 7, 8, 5, 3, 1 },
					{ 9, 7, 8, 5, 3, 1, 6, 4, 2 } },
			{ { 3, 9, 4, 5, 1, 7, 6, 2, 8 }, { 5, 1, 7, 6, 2, 8, 3, 9, 4 },
					{ 6, 2, 8, 3, 9, 4, 5, 1, 7 },
					{ 9, 3, 5, 4, 7, 1, 2, 8, 6 },
					{ 4, 7, 1, 2, 8, 6, 9, 3, 5 },
					{ 2, 8, 6, 9, 3, 5, 4, 7, 1 },
					{ 1, 4, 3, 7, 5, 9, 8, 6, 2 },
					{ 7, 5, 9, 8, 6, 2, 1, 4, 3 },
					{ 8, 6, 2, 1, 4, 3, 7, 5, 9 } },
			{ { 7, 6, 1, 9, 8, 4, 2, 3, 5 }, { 9, 8, 4, 2, 3, 5, 7, 6, 1 },
					{ 2, 3, 5, 7, 6, 1, 9, 8, 4 },
					{ 6, 7, 9, 1, 4, 8, 3, 5, 2 },
					{ 1, 4, 8, 3, 5, 2, 6, 7, 9 },
					{ 3, 5, 2, 6, 7, 9, 1, 4, 8 },
					{ 8, 1, 7, 4, 9, 6, 5, 2, 3 },
					{ 4, 9, 6, 5, 2, 3, 8, 1, 7 },
					{ 5, 2, 3, 8, 1, 7, 4, 9, 6 } },
			{ { 7, 1, 5, 4, 3, 6, 2, 9, 8 }, { 4, 3, 6, 2, 9, 8, 7, 1, 5 },
					{ 2, 9, 8, 7, 1, 5, 4, 3, 6 },
					{ 1, 7, 4, 5, 6, 3, 9, 8, 2 },
					{ 5, 6, 3, 9, 8, 2, 1, 7, 4 },
					{ 9, 8, 2, 1, 7, 4, 5, 6, 3 },
					{ 3, 5, 7, 6, 4, 1, 8, 2, 9 },
					{ 6, 4, 1, 8, 2, 9, 3, 5, 7 },
					{ 8, 2, 9, 3, 5, 7, 6, 4, 1 } } };

static int trans[9][9][9] = { {{0,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1}}
,
{{0,0,1,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1}}
,
{{1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1}}
,
{{1,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1}}
,
{{1,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1}}
,
{{1,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1}}
,
{{1,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1}}
,
{{1,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0,0}}
,
{{1,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,0}}
};

void initQuestion(int suku[9][9], int difficult);

int isRepeat(int suku[9][9], int i, int j);

void dfs_solves_count(int suku[9][9], int count, int *n);

void isOnlySolve(int suku[9][9], int count, int *n);

void initEasyQuestion(int suku[9][9], int difficult);