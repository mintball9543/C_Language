#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{


	int com1;
	int com2;
	int com3;
	int user1;
	int user2;
	int user3;
	int st;
	int ball;
	int out;
	int count = 0;

	srand(time(0));

	com1 = rand() % 10;
	for (;;)
	{
		com2 = rand() % 10;
		if (com1 != com2) break;
	}

	for (;;)
	{
		com3 = rand() % 10;
		if (com3 != com1 && com3 != com2) break;
	}

	for (;;)
	{
		st = ball = out = 0;

		printf("숫자를 3개를 입력하세요 : ");
		scanf("%d %d %d", &user1, &user2, &user3);

		if (com1 == user1)
			st++;
		else if (com1 == user2 || com1 == user3)
			ball++;
		else
			out++;

		if (com2 == user2)
			st++;
		else if (com2 == user1 || com2 == user3)
			ball++;
		else
			out++;

		if (com3 == user3)
			st++;
		else if (com3 == user1 || com3 == user2)
			ball++;
		else
			out++;

		printf("%d회차 결과 : %d스트라이크 / %d볼 / %d아웃\n\n", ++count, st, ball, out);
		if (com1 == user1 && com2 == user2 && com3 == user3) break;
	}

	printf("승리!\n");

	return 0;
}