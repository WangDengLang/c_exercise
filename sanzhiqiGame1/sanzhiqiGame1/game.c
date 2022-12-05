#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
//��Ϸ��ʼ��//������ȫ��ո�
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
}////�ҵĴ��룺�ҵİ�if����forѭ�����ʦ������if�ſ�ʼѭ���ģ��ҵ��ǽ���ѭ���˲��ж���ʵû�б�Ҫ�����ܶ�һ����if��������ã���Ϊ���̵ĺ��߱�col��һ
void Qi_Pan(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//�м���
	{
		int j = 0;
		for (j = 0; j < col; j++)//һ�д�ӡ���ٸ�' '|
		{
			printf(" %c ",board[i][j]);
			if(j<(col-1))
				printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)//��һ�д�ӡ���ٸ�'---|'
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

////��ʦ�Ĵ���
//void Qi_Pan(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)//�м���
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)//һ�д�ӡ���ٸ�' '|
//		{
//			printf(" %c ", board[i][j]);
//			if (j < (col - 1))
//				printf("|");
//		}
//		printf("\n");
//		if (i < row - 1)
//		{
//			int j = 0;
//			for (j = 0; j < col; j++)//��һ�д�ӡ���ٸ�'---|'
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
	printf("����£�\n");
	while (1)
	{	
		printf("������λ��:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ڲ����̵��������̵�һ����1 1����Ҫ������Щ����
		{
			if (board[x-1][y-1] == ' ')//�ж���һ���Ƿ��Ѿ�����
			{
				board[x - 1][y - 1] = '*';//��ҵ�����*
				break;
			}
			else
			{
				printf("���걻ռ��,���������룺\n");
			}
		}
		else
		{
			printf("��λ�ò��Ϸ�������������\n");
		}
	}
	

}

void Computer_Move(char board[ROW][COL], int row, int col)
{
	printf("������;\n");
	while (1)
	{
		int x = rand()%row;//��Ϊ�������������������ȡ�����
		int y = rand()%col;
		if (board[x][y] == ' ')//�ж���һ���Ƿ��Ѿ�����
		{
			board[x][y] = '#';//���Ե�����#
			break;
		}
	}
}

int Is_Q(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][1] != ' ')//�ж�һ���Ƿ����
		{
			return board[i][1];//����#/*�����ж�˭Ӯ
		}
	}
	//�����
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')//�ж�һ���Ƿ����
		{
			return board[1][i];//����#/*�����ж�˭Ӯ
		}
	}
	//�Խ����
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];//����#/*�����ж�˭Ӯ
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];//����#/*�����ж�˭Ӯ
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
		for (j = 0; j < col; j++)//���������Ƿ�����
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}


