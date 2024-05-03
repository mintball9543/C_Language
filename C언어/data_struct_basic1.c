#include<stdio.h>
#include<Windows.h>

void input(int* parr, int pindex);
void output(int* parr, int pindex);
void modify(int *parr, int pindex);
void delete(int* parr, int pindex);
void insert(int* parr, int pindex);
int copy(int* parr, int pindex);
void paste(int* parr, int pindex, int copy_data);
FILE* makefile(int pwrite);
void filesave(FILE* fptr, int* parr, int pindex);
int fileload(FILE** pfile, int* parr);
void ui();

int main()
{
	int arr[10] = { 0 };
	int index = 0;
	int menu = 0;
	int copy_area=0;
	FILE* fptr = 0;

	while (1) {
		//printf("menu: 1.input 2.output 3.modify 4.delete 5.insert 6.copy 7.paste 8.���ϻ��� 9.���Ͽ� ���� 10.���� �ҷ����� 11.exit\n");
		//printf("select menu:");
		
		ui();
		scanf("%d",&menu);

		switch (menu) {
		case 1:
			input(arr, index);
			index++;
			break;
		case 2:
			output(arr, index);

			break;
		case 3:
			modify(arr, index);
			break;
		case 4:
			delete(arr, index);
			index--;
			break;
		case 5:
			insert(arr, index);
			index++;
			break;
		case 6:
			copy_area = copy(arr, index);
			break;
		case 7:
			paste(arr, index, copy_area);
			break;
		case 8:
			fptr=makefile(1);
			break;
		case 9:
			filesave(fptr, arr, index);
			break;
		case 10:
			index=fileload(&fptr, arr);
			index--;
		
			break;
		}

		if (menu == 11) {
			fclose(fptr);

			break;
		}
	}
		return 0;
}

void input(int* parr, int pindex)
{
	printf("���� �Ѱ��� �Է��ϼ���: ");
	scanf("%d", &parr[pindex]);
}

void output(int* parr, int pindex)
{
	int i = 0;

	for (i = 0; i < pindex; i++)
	{
		printf("%d\n", parr[i]);
	}

	return;
}

void modify(int* parr,int pindex)
{
	int part = 0;
	
	output(parr, pindex);

	printf("�����Ͻ� �κ��� ���°�ΰ���?: ");
	scanf("%d", &part);

	printf("������ ���ڸ� �Է��ϼ���: ");
	scanf("%d", &parr[part-1]);
}

void delete(int *parr, int pindex)
{
	int part = 0;
	int i = 0;

	output(parr, pindex);

	printf("�����Ͻ� �κ��� ���°�ΰ���?: ");
	scanf("%d", &part);

	parr[part - 1] = 0;

	for (i = part - 1; i < pindex; i++)
	{
		parr[i] = parr[i + 1];
	}

	return;
}

void insert(int* parr, int pindex)
{
	int i = 0;
	int part = 0;

	output(parr, pindex);

	printf("���°�� ���� �߰��Ͻðڽ��ϱ�?: ");
	scanf("%d", &part);

	for (i = pindex; i >= part; i--)
	{
		parr[i] = parr[i - 1];
	}

	printf("�߰��Ͻ� ���� �Է��ϼ���: ");
	scanf("%d", &parr[part - 1]);



	return;
}

int copy(int* parr, int pindex)
{
	int value;
	int part=0;

	output(parr, pindex);
	printf("���° ���� �����Ͻðڽ��ϱ�?: ");
	scanf("%d", &part);

	value = parr[part - 1];

	return value;
}

void paste(int* parr, int pindex, int copy_data)
{
	int part = 0;
	int check = 0;

	if (copy_data == 0)
	{
		printf("����� ���� �����Ƿ� �ٿ����� �� �����ϴ�\n");
		return;
	}

	output(parr, pindex);
	printf("���°�� ���� �ٿ��ְڽ��ϱ�?: ");
	scanf("%d", &part);

	if (parr[part - 1] != 0)
	{
		printf("�̹� ���� �����մϴ� �׷��� �ٿ������ðڽ��ϱ�?\n1.yes 2.no: ");
		scanf("%d", &check);

		if (check == 1)
			parr[part - 1] = copy_data;
		else if (check == 2)
			return;
		else
			printf("error\n");
	}
	else
		parr[part - 1] = copy_data;
	
	

	return;
}

FILE* makefile(int pwrite)
{
	FILE* fp;
	char filename[128] = { 0 };

	printf("���ϸ� �Է�: ");
	while (getchar() != '\n');
	gets_s(filename, 128);

	if (pwrite)
		fp = fopen(filename, "w+");
	else
		fp = fopen(filename, "r+");



	return fp;
}

void filesave(FILE* fptr, int* parr, int pindex)
{
	int i = 0;

	for (i = 0; i < pindex; i++)
	{
		fprintf(fptr, "%d\t", *(parr + i));
	}

	printf("���Ͽ� ������ ���� �Ϸ�\n");
	
	fflush(fptr);

	return;
}

int fileload(FILE** pfile, int* parr) {

	int i = 0;
	int index = 0;

	

	if (*pfile == NULL)
	{
		*pfile=makefile(0);
	}

	

	for (i = 0;;i++)
	{		
		if (feof(*pfile) != 0) break;
		fscanf(*pfile, "%d", parr+i);

	}
	index = i;

	return index;
}


void ui()
{
	HANDLE hdle;
	COORD coord;

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);

	coord.X = 10;
	coord.Y = 5;

	SetConsoleCursorPosition(hdle, coord);

	printf("��������������������������������������������������������������������������������������������\n");
	coord.X = 10;
	coord.Y = 6;
	SetConsoleCursorPosition(hdle, coord);
	printf("��                                            ��\n");
	coord.X = 10;
	coord.Y = 7;
	SetConsoleCursorPosition(hdle, coord);
	printf("��                                            ��\n");
	coord.X = 10;
	coord.Y = 8;
	SetConsoleCursorPosition(hdle, coord);
	printf("��                                            ��\n");
	coord.X = 10;
	coord.Y = 9;
	SetConsoleCursorPosition(hdle, coord);
	printf("��                                            ��\n");
	coord.X = 10;
	coord.Y = 9;
	SetConsoleCursorPosition(hdle, coord);
	printf("��������������������������������������������������������������������������������������������\n");

	coord.X = 23;
	coord.Y = 7;
	SetConsoleCursorPosition(hdle, coord);
	printf("���� ���� ���α׷�\n");

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

	printf("8.���� ����");

	coord.X = 42;
	coord.Y = 18;
	SetConsoleCursorPosition(hdle, coord);

	printf("9.���Ͽ� ����");

	coord.X = 12;
	coord.Y = 21;
	SetConsoleCursorPosition(hdle, coord);

	printf("10.���� �ҷ�����");

	coord.X = 42;
	coord.Y = 21;
	SetConsoleCursorPosition(hdle, coord);

	printf("11.exit");

	coord.X = 12;
	coord.Y = 23;
	SetConsoleCursorPosition(hdle, coord);
	printf("select menu: ");

	return;
}