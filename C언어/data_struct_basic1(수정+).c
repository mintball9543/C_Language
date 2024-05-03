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
		//printf("menu: 1.input 2.output 3.modify 4.delete 5.insert 6.copy 7.paste 8.파일생성 9.파일에 저장 10.파일 불러오기 11.exit\n");
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
	
	printf("숫자 한개를 입력하세요: ");
	scanf("%d", &data[pindex].num);
	while (1) {
		if (getchar() == '\n') break;
	}

	printf("문자를 입력하세요: ");
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

	printf("수정하실 부분이 몇번째인가요?: ");
	scanf("%d", &part);

	printf("수정할 숫자를 입력하세요: ");
	scanf("%d", &data[part-1].num);
	while (1) {
		if (getchar() == '\n') break;
	}

	printf("수정할 문자를 입력하세요: ");
	gets_s(data[part-1].str, 128);
}

void delete(struct test* data, int pindex)
{
	int part = 0;
	int i = 0;

	output(data, pindex);

	printf("삭제하실 부분이 몇번째인가요?: ");
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

	printf("몇번째에 값을 추가하시겠습니까?: ");
	scanf("%d", &part);

	for (i = pindex; i >= part; i--)
	{
		data[i].num = data[i - 1].num;
		strcpy(data[i].str, data[i - 1].str);

	}

	printf("추가하실 숫자를 입력하세요: ");
	scanf("%d", &data[part - 1].num);
	while (1) {
		if (getchar() == '\n') break;
	}

	printf("추가하실 문자를 입력하세요: ");
	gets_s(data[part - 1].str, 128);



	return;
}

struct test copy(struct test* data, int pindex)
{
	struct test value;
	int part=0;

	output(data, pindex);
	printf("몇번째 값을 복사하시겠습니까?: ");
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
		printf("복사된 값이 없으므로 붙여넣을 수 없습니다\n");
		return;
	}

	output(data, pindex);
	printf("몇번째에 값을 붙여넣겠습니까?: ");
	scanf("%d", &part);

	if (data[part - 1].num != 0)
	{
		printf("이미 값이 존재합니다 그래도 붙여넣으시겠습니까?\n1.yes 2.no: ");
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

	printf("파일명 입력: ");
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

	printf("파일에 데이터 쓰기 완료\n");
	
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

	return;
}