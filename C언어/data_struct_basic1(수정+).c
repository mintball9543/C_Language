#include<stdio.h>
#include<Windows.h>
#include<io.h>


struct test {
	int num;
	char str[128];
};

void input(struct test *data, int pindex);
void output(struct test* data, int pindex);
void modify(struct test* data, int pindex);
void delete(struct test* data, int pindex);
void insert(struct test* data, int pindex);
struct test copy(struct test* data, int pindex);
void paste(struct test* data, int pindex, struct test copy_data);
FILE* makefile(int pwrite);
void filesave(FILE* fptr, struct test* data, int pindex);
int fileload(FILE** pfile, struct test* data);
void ui();


int main()
{
	struct test data[100];
	int arr[10] = { 0 };
	int index = 0;
	int menu = 0;
	struct test copy_area = { 0 };
	FILE* fptr = 0;
	
	while (1) {
		//printf("menu: 1.input 2.output 3.modify 4.delete 5.insert 6.copy 7.paste 8.���ϻ��� 9.���Ͽ� ���� 10.���� �ҷ����� 11.exit\n");
		//printf("select menu:");
		
		ui();
		scanf("%d",&menu);
		system("cls");

		switch (menu) {
		case 1:
			input(data, index);
			index++;
			break;
		case 2:
			output(data, index);

			break;
		case 3:
			modify(data, index);
			break;
		case 4:
			delete(data, index);
			index--;
			break;
		case 5:
			insert(data, index);
			index++;
			break;
		case 6:
			copy_area = copy(data, index);
			break;
		case 7:
			paste(data, index, copy_area);
			break;
		case 8:
			fptr=makefile(1);
			break;
		case 9:
			filesave(fptr, data, index);
			break;
		case 10:
			index=fileload(&fptr, data);
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

void input(struct test *data, int pindex)
{
	
	printf("���� �Ѱ��� �Է��ϼ���: ");
	scanf("%d", &data[pindex].num);
	while (1) {
		if (getchar() == '\n') break;
	}

	printf("���ڸ� �Է��ϼ���: ");
	gets_s(data[pindex].str, 128);
}

void output(struct test* data, int pindex)
{
	int i = 0;

	for (i = 0; i < pindex; i++)
	{
		printf("%d ", data[i].num);
		printf("%s\n", data[i].str);
	}

	return;
}

void modify(struct test* data, int pindex)
{
	int part = 0;
	
	output(data, pindex);

	printf("�����Ͻ� �κ��� ���°�ΰ���?: ");
	scanf("%d", &part);

	printf("������ ���ڸ� �Է��ϼ���: ");
	scanf("%d", &data[part-1].num);
	while (1) {
		if (getchar() == '\n') break;
	}

	printf("������ ���ڸ� �Է��ϼ���: ");
	gets_s(data[part-1].str, 128);
}

void delete(struct test* data, int pindex)
{
	int part = 0;
	int i = 0;

	output(data, pindex);

	printf("�����Ͻ� �κ��� ���°�ΰ���?: ");
	scanf("%d", &part);

	data[part - 1].num = 0;

	for (i = 0; i < 128; i++)
	{
		data[part - 1].str[i] = NULL;
	}

	for (i = part - 1; i < pindex; i++)
	{
		data[i].num = data[i + 1].num;
		strcpy(data[i].str, data[i + 1].str);
	}

	return;
}

void insert(struct test* data, int pindex)
{
	int i = 0;
	int part = 0;
	int j = 0;
	output(data, pindex);

	printf("���°�� ���� �߰��Ͻðڽ��ϱ�?: ");
	scanf("%d", &part);

	for (i = pindex; i >= part; i--)
	{
		data[i].num = data[i - 1].num;
		strcpy(data[i].str, data[i - 1].str);

	}

	printf("�߰��Ͻ� ���ڸ� �Է��ϼ���: ");
	scanf("%d", &data[part - 1].num);
	while (1) {
		if (getchar() == '\n') break;
	}

	printf("�߰��Ͻ� ���ڸ� �Է��ϼ���: ");
	gets_s(data[part - 1].str, 128);



	return;
}

struct test copy(struct test* data, int pindex)
{
	struct test value;
	int part=0;

	output(data, pindex);
	printf("���° ���� �����Ͻðڽ��ϱ�?: ");
	scanf("%d", &part);

	value.num = data[part - 1].num;
	strcpy(value.str, data[part - 1].str);

	return value;
}

void paste(struct test* data, int pindex, struct test copy_data)
{
	int part = 0;
	int check = 0;
	int i = 0;

	if (copy_data.num == 0)
	{
		printf("����� ���� �����Ƿ� �ٿ����� �� �����ϴ�\n");
		return;
	}

	output(data, pindex);
	printf("���°�� ���� �ٿ��ְڽ��ϱ�?: ");
	scanf("%d", &part);

	if (data[part - 1].num != 0)
	{
		printf("�̹� ���� �����մϴ� �׷��� �ٿ������ðڽ��ϱ�?\n1.yes 2.no: ");
		scanf("%d", &check);

		if (check == 1)
		{
			data[part - 1].num = copy_data.num;
			strcpy(data[part - 1].str, copy_data.str);
		}
		else if (check == 2)
			return;
		else
			printf("error\n");
	}
	else
		data[part - 1].num = copy_data.num;
		strcpy(data[part - 1].str, copy_data.str);
	
	

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

void filesave(FILE* fptr, struct test* data, int pindex)
{
	int i = 0;

	for (i = 0; i < pindex; i++)
	{
		fprintf(fptr, "%d\t%s\n", data[i].num,data[i].str);
	}

	printf("���Ͽ� ������ ���� �Ϸ�\n");
	
	fflush(fptr);

	return;
}

int fileload(FILE** pfile, struct test* data) {

	int i = 0;
	int index = 0;

	

	if (*pfile == NULL)
	{
		*pfile=makefile(0);
	}

	

	for (i = 0;;i++)
	{		
		if (feof(*pfile) != 0) break;
		fscanf(*pfile, "%d\t%s", &data[i].num,&data[i].str);
		fgetc(*pfile);

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