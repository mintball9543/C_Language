#include<Windows.h>
#include<stdio.h>

int main()
{
	HANDLE hdle;
	COORD coord;

	hdle=GetStdHandle(STD_OUTPUT_HANDLE);

	coord.X = 10;
	coord.Y = 5;

	SetConsoleCursorPosition(hdle, coord);

	printf("┌────────────────────────────────────────────┐\n");
	coord.X = 10;
	coord.Y = 6;
	SetConsoleCursorPosition(hdle, coord);
	printf("│                                            │\n");
	coord.X = 10;
	coord.Y = 7;
	SetConsoleCursorPosition(hdle, coord);
	printf("│                                            │\n");
	coord.X = 10;
	coord.Y = 8;
	SetConsoleCursorPosition(hdle, coord);
	printf("│                                            │\n");
	coord.X = 10;
	coord.Y = 9;
	SetConsoleCursorPosition(hdle, coord);
	printf("│                                            │\n");
	coord.X = 10;
	coord.Y = 9;
	SetConsoleCursorPosition(hdle, coord);
	printf("└────────────────────────────────────────────┘\n");

	coord.X = 23;
	coord.Y = 7;
	SetConsoleCursorPosition(hdle, coord);
	printf("숫자 관리 프로그램\n");

	coord.X = 12;
	coord.Y = 12;
	SetConsoleCursorPosition(hdle, coord);

	printf("1.input");

	coord.X = 27;
	coord.Y = 12;
	SetConsoleCursorPosition(hdle, coord);

	printf("2.output");

	coord.X = 42;
	coord.Y = 12;
	SetConsoleCursorPosition(hdle, coord);

	printf("3.modify");

	coord.X = 12;
	coord.Y = 15;
	SetConsoleCursorPosition(hdle, coord);

	printf("4.delete");

	coord.X = 27;
	coord.Y = 15;
	SetConsoleCursorPosition(hdle, coord);

	printf("5.insert");

	coord.X = 42;
	coord.Y = 15;
	SetConsoleCursorPosition(hdle, coord);

	printf("6.copy");

	coord.X = 12;
	coord.Y = 18;
	SetConsoleCursorPosition(hdle, coord);

	printf("7.paste");

	coord.X = 27;
	coord.Y = 18;
	SetConsoleCursorPosition(hdle, coord);

	printf("8.파일 생성");

	coord.X = 42;
	coord.Y = 18;
	SetConsoleCursorPosition(hdle, coord);

	printf("9.파일에 저장");

	coord.X = 12;
	coord.Y = 21;
	SetConsoleCursorPosition(hdle, coord);

	printf("10.파일 불러오기");

	coord.X = 42;
	coord.Y = 21;
	SetConsoleCursorPosition(hdle, coord);

	printf("11.exit");

	coord.X = 12;
	coord.Y = 23;
	SetConsoleCursorPosition(hdle, coord);
	printf("select menu: ");
	
	return 0;
}