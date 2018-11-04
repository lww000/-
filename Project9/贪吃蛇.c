#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

#define H 23
#define W 75

int a[H][W];        //地图数组
int s[H*W][2];      //蛇身坐标数组
int sLength;        //蛇的长度
void init()         //程序开始时的初始化操作
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);    //隐藏关标
	int i, j;
	for (i = 0; i < H; i++)
	{
		a[i][0] = 1;          //让第一列为1
		a[i][W - 1] = 1;        //让最后一列为1
	}
	for (j = 0; j < W; j++)
	{
		a[0][j] = 1;      //让第一行为1
		a[H - 1][j] = 1;    //让最后一行为1
	}
	sLength = 4;          //让蛇的最初长度为4
	s[0][0] = H / 2;
	s[0][1] = W / 2;        //给蛇头坐标赋值
	for (i = 1; i < 4; i++)
	{
		s[i][0] = s[0][0] + i;
		s[i][1] = s[0][1];  //给刚开始的蛇身几个初始坐标
	}

}

void gotoxy(int i, int j)        //移动光标
{
	COORD position = { j,i };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void drawMap()                  //画地图
{
	int i, j;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)            //两重for循环遍历数组
		{
			if (a[i][j] == 0)          //为0输出空格
				printf(" ");
			else                    //为1输出#
				printf("#");
		}
		printf("\n");               //别忘了换行
	}
}

void drawSnake()                //画蛇
{
	int i;
	for (i = 0; i < sLength; i++)
	{
		gotoxy(s[i][0], s[i][1]);        //移动关标到蛇的坐标
		printf("@");                    //在这个位置画蛇
	}
}

int main()
{
	init();                     //程序开始时的初始化操作
	drawMap();                  //画地图
	drawSnake();                //画蛇
	getchar();
	return 0;
}
