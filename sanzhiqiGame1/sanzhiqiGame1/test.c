#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void meau()
{
	printf("******************************\n");
	printf("******    1.��ʼ��Ϸ    ******\n");
	printf("******	  0.�˳���Ϸ    ******\n");
	printf("******************************\n");
}
  
void game1()
{
	char board[ROW][COL];
	int ret = 0;
	Board_Init(board, ROW, COL);//��ʼ������
	//����
	Qi_Pan(board, ROW, COL);
	while (1)
	{
		//�����
		Player_Move(board, ROW, COL);
		Qi_Pan(board, ROW, COL);
		//�ж��Ƿ�Ӯ
		ret=Is_Q(board, ROW, COL);
		if (ret != 'C')
			break;
		//������
		Computer_Move(board, ROW, COL);
		//�ж��Ƿ�Ӯ
		Qi_Pan(board, ROW, COL);
		ret = Is_Q(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
		Qi_Pan(board, ROW, COL);
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
		Qi_Pan(board, ROW, COL);
	}
	else if(ret == 'Q')
	{
		printf("ƽ��\n");
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
		printf("������:>");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				printf("������\n");
				game1();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("�������������ѡ��\n");
				break;		
		}
	}while(input);
	return 0;
}