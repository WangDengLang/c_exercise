#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
//游戏初始化//把数组全填空格
void Board_Init(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}////我的代码：我的把if放在for循环里，老师的是先if才开始循环的，我的是进入循环了才判断其实没有必要，功能都一样但if放外面更好，因为棋盘的横线比col少一
void Qi_Pan(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//有几行
	{
		int j = 0;
		for (j = 0; j < col; j++)//一行打印多少个' '|
		{
			printf(" %c ",board[i][j]);
			if(j<(col-1))
				printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)//下一行打印多少个'---|'
		{
			if (i < row - 1)
			{
				printf("---");
				if (j < (col - 1))
				printf("|");
			}
		}
		printf("\n");
	}
}

////老师的代码
//void Qi_Pan(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)//有几行
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)//一行打印多少个' '|
//		{
//			printf(" %c ", board[i][j]);
//			if (j < (col - 1))
//				printf("|");
//		}
//		printf("\n");
//		if (i < row - 1)
//		{
//			int j = 0;
//			for (j = 0; j < col; j++)//下一行打印多少个'---|'
//			{
//			
//				printf("---");
//				if (j < (col - 1))
//				printf("|");
//			}
//		}
//		printf("\n");
//	}
//}

void Player_Move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下：\n");
	while (1)
	{	
		printf("请输入位置:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//在不会编程的眼里棋盘第一格是1 1所以要满足这些条件
		{
			if (board[x-1][y-1] == ' ')//判断这一格是否已经被下
			{
				board[x - 1][y - 1] = '*';//玩家的棋子*
				break;
			}
			else
			{
				printf("坐标被占用,请重新输入：\n");
			}
		}
		else
		{
			printf("此位置不合法，请重新输入\n");
		}
	}
	

}

void Computer_Move(char board[ROW][COL], int row, int col)
{
	printf("电脑下;\n");
	while (1)
	{
		int x = rand()%row;//因为是三子棋所以用这个获取随机数
		int y = rand()%col;
		if (board[x][y] == ' ')//判断这一格是否已经被下
		{
			board[x][y] = '#';//电脑的棋子#
			break;
		}
	}
}

int Is_Q(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//行相等
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][1] != ' ')//判断一行是否相等
		{
			return board[i][1];//返回#/*用来判断谁赢
		}
	}
	//列相等
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')//判断一列是否相等
		{
			return board[1][i];//返回#/*用来判断谁赢
		}
	}
	//对角相等
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];//返回#/*用来判断谁赢
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];//返回#/*用来判断谁赢
	}
	if (Is_Full(board,row,col) == 1)
	{
		return 'Q';
	}
	return 'C';
}

int Is_Full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)//遍历棋盘是否填满
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}


