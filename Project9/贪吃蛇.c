#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

#define H 23
#define W 75

int a[H][W];        //��ͼ����
int s[H*W][2];      //������������
int sLength;        //�ߵĳ���
void init()         //����ʼʱ�ĳ�ʼ������
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);    //���عر�
	int i, j;
	for (i = 0; i < H; i++)
	{
		a[i][0] = 1;          //�õ�һ��Ϊ1
		a[i][W - 1] = 1;        //�����һ��Ϊ1
	}
	for (j = 0; j < W; j++)
	{
		a[0][j] = 1;      //�õ�һ��Ϊ1
		a[H - 1][j] = 1;    //�����һ��Ϊ1
	}
	sLength = 4;          //���ߵ��������Ϊ4
	s[0][0] = H / 2;
	s[0][1] = W / 2;        //����ͷ���긳ֵ
	for (i = 1; i < 4; i++)
	{
		s[i][0] = s[0][0] + i;
		s[i][1] = s[0][1];  //���տ�ʼ����������ʼ����
	}

}

void gotoxy(int i, int j)        //�ƶ����
{
	COORD position = { j,i };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void drawMap()                  //����ͼ
{
	int i, j;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)            //����forѭ����������
		{
			if (a[i][j] == 0)          //Ϊ0����ո�
				printf(" ");
			else                    //Ϊ1���#
				printf("#");
		}
		printf("\n");               //�����˻���
	}
}

void drawSnake()                //����
{
	int i;
	for (i = 0; i < sLength; i++)
	{
		gotoxy(s[i][0], s[i][1]);        //�ƶ��ر굽�ߵ�����
		printf("@");                    //�����λ�û���
	}
}

int main()
{
	init();                     //����ʼʱ�ĳ�ʼ������
	drawMap();                  //����ͼ
	drawSnake();                //����
	getchar();
	return 0;
}
