#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3
void Qi_Pan(char board[ROW][COL], int row, int col);
void Board_Init(char board[ROW][COL], int row, int col);
void Player_Move(char board[ROW][COL], int row, int col);
void Computer_Move(char board[ROW][COL], int row, int col);
int Is_Q(char board[ROW][COL], int row, int col);
int Is_Full(char board[ROW][COL], int row, int col);
