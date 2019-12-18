#pragma once

constexpr auto BLOCKS_WIDE = 50;

//constexpr auto;

void init_graph();

void repaint_board();

void repaint_cell(int suku[9][9], int i, int j);

void dfs_draw(int suku[9][9], int count, int *n);

void draw_suku(int suku[9][9]);