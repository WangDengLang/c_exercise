#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void meau()
{
	printf("******************************\n");
	printf("******    1.开始游戏    ******\n");
	printf("******	  0.退出游戏    ******\n");
	printf("******************************\n");
}
  
void game1()
{
	char board[ROW][COL];
	int ret = 0;
	Board_Init(board, ROW, COL);//初始化数组
	//棋盘
	Qi_Pan(board, ROW, COL);
	while (1)
	{
		//玩家下
		Player_Move(board, ROW, COL);
		Qi_Pan(board, ROW, COL);
		//判断是否赢
		ret=Is_Q(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下
		Computer_Move(board, ROW, COL);
		//判断是否赢
		Qi_Pan(board, ROW, COL);
		ret = Is_Q(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
		Qi_Pan(board, ROW, COL);
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
		Qi_Pan(board, ROW, COL);
	}
	else if(ret == 'Q')
	{
		printf("平局\n");
		Qi_Pan(board, ROW, COL);
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{	
		meau();
		printf("请输入:>");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				printf("三子棋\n");
				game1();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误，请重新选择\n");
				break;		
		}
	}while(input);
	return 0;
}