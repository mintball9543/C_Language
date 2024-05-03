#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<io.h>
#include<time.h>

typedef struct student {
	char num[128];
	char name[128];
	int score;
	struct student* next;
	struct student* prev;
}student;

student* createnode();
student* inputdata();
student* addlist(student* ptail);
void printdata(student* phead, student* ptail);
void delete(student* phead, student* ptail);
void modify(student* phead, student* ptail);
void insert(student* phead, student* ptail);
void ui();
FILE* filesave(student* phead);
student* fileload(student** phead, student** ptail);
void DirView(const char* pstr);

HANDLE hdle;
COORD coord;



int main() {
	int menu;
	student* head;
	student* tail;
	head = tail = NULL;
	char temp = 0;
	

	while (1) {
		ui();
		scanf("%d", &menu);
		system("cls");
		switch (menu) {
		case 1: //추가
			tail = addlist(tail);
			if (head == NULL)
				head = tail;

			hdle = GetStdHandle(STD_OUTPUT_HANDLE);
			coord.X = 10;
			coord.Y += 3;
			SetConsoleCursorPosition(hdle, coord);
			printf("계속하시려면 아무키나 누르세요.");
			while (getchar() != '\n');
			scanf("%c", &temp);
			break;
		case 2: //출력
			printdata(head, tail);
			hdle = GetStdHandle(STD_OUTPUT_HANDLE);
			coord.X = 10;
			coord.Y+=3;
			SetConsoleCursorPosition(hdle, coord);
			printf("계속하시려면 아무키나 누르세요.");
			while (getchar() != '\n');
			scanf("%c", &temp);
			break;
		case 3: //삭제
			delete(head, tail);
			hdle = GetStdHandle(STD_OUTPUT_HANDLE);
			coord.X = 10;
			coord.Y += 3;
			SetConsoleCursorPosition(hdle, coord);
			printf("계속하시려면 아무키나 누르세요.");
			while (getchar() != '\n');
			scanf("%c", &temp);

			break;
		case 4: //수정
			modify(head, tail);
			hdle = GetStdHandle(STD_OUTPUT_HANDLE);
			coord.X = 10;
			coord.Y += 3;
			SetConsoleCursorPosition(hdle, coord);
			printf("계속하시려면 아무키나 누르세요.");
			while (getchar() != '\n');
			scanf("%c", &temp);
			break;
		case 5: //삽입
			insert(head, tail);
			hdle = GetStdHandle(STD_OUTPUT_HANDLE);
			coord.X = 10;
			coord.Y += 3;
			SetConsoleCursorPosition(hdle, coord);
			printf("계속하시려면 아무키나 누르세요.");
			while (getchar() != '\n');
			scanf("%c", &temp);
			break;
		case 6: //저장
			filesave(head);
			break;
		case 7: //불러오기
			fileload(&head, &tail);
			break;
		case 10:
			break;
		default:
			hdle = GetStdHandle(STD_OUTPUT_HANDLE);
			coord.X = 10;
			coord.Y =6;
			SetConsoleCursorPosition(hdle, coord);

			printf("다시 입력해주세요\n");
			
			hdle = GetStdHandle(STD_OUTPUT_HANDLE);
			coord.X = 10;
			coord.Y++;
			SetConsoleCursorPosition(hdle, coord);

			printf("계속하시려면 아무키나 누르세요.");
			while (getchar() != '\n');
			scanf("%c", &temp);
			break;
		}
		system("cls");
		if (menu == 10)
			break;
	}


	return 0;
}

student* createnode() {
	student* temp = { 0 };
	temp = malloc(sizeof(student));

	temp->next = temp->prev = NULL;

	return temp;
}

student* addlist(student* ptail) {
	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y = 6;
	SetConsoleCursorPosition(hdle, coord);

	student* new_node;
	new_node = createnode();

	new_node = inputdata();

	if (ptail == NULL)
		return new_node;

	ptail->next = new_node;
	new_node->prev = ptail;


	return new_node;
}

void printdata(student* phead, student* ptail) {
	int temp = 0;

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y = 6;
	SetConsoleCursorPosition(hdle, coord);

	printf("※수정이나 삭제시 순차적 출력해야함※\n");

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y++;
	SetConsoleCursorPosition(hdle, coord);

	printf("1.순차적 출력 2.역출력: ");
	scanf("%d", &temp);

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y+=2;
	SetConsoleCursorPosition(hdle, coord);

	if (temp == 1) {
		while (1) {
			hdle = GetStdHandle(STD_OUTPUT_HANDLE);
			coord.X = 10;
			coord.Y++;
			SetConsoleCursorPosition(hdle, coord);

			printf("%s ", phead->num);
			printf("%s ", phead->name);
			printf("%d\n", phead->score);

			phead = phead->next;

			if (phead == NULL) break;
		}
	}
	else if(temp == 2) {
		while (1) {
			hdle = GetStdHandle(STD_OUTPUT_HANDLE);
			coord.X = 10;
			coord.Y++;
			SetConsoleCursorPosition(hdle, coord);

			printf("%s ", ptail->num);
			printf("%s ", ptail->name);
			printf("%d\n", ptail->score);

			ptail = ptail->prev;
			if (ptail == NULL) break;
		}
	}

	return;
}

void delete(student* phead, student* ptail) {
	int temp = 0;
	int i = 0;

	printdata(phead, ptail);

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y += 3;
	SetConsoleCursorPosition(hdle, coord);

	printf("삭제하실 부분을 선택하세요: ");
	while (getchar() != '\n');
	scanf("%d", &temp);

	for (i = 0; i < temp-1; i++) {
		phead = phead->next;
	}

	phead->prev->next = phead->next;
	phead->next->prev = phead->prev;

	free(phead);

	return;
}

void modify(student* phead, student* ptail) {
	int temp = 0;
	int i = 0;

	printdata(phead, ptail);
	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y += 3;
	SetConsoleCursorPosition(hdle, coord);
	printf("수정하실 부분을 선택하세요: ");
	scanf("%d", &temp);

	for (i = 0; i < temp - 1; i++) {
		phead = phead->next;
	}
	
	while (getchar() != '\n') break;
	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y += 2;
	SetConsoleCursorPosition(hdle, coord);
	printf("학번을 입력하세요: ");
	gets_s(phead->num, 128);

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y += 2;
	SetConsoleCursorPosition(hdle, coord);
	printf("이름을 입력하세요: ");
	gets_s(phead->name, 128);

	while (1) {
		hdle = GetStdHandle(STD_OUTPUT_HANDLE);
		coord.X = 10;
		coord.Y += 2;
		SetConsoleCursorPosition(hdle, coord);
		printf("학점을 입력하세요: ");
		scanf("%d", &phead->score);

		if (phead->score <= 100)
			break;
		else {
			hdle = GetStdHandle(STD_OUTPUT_HANDLE);
			coord.X = 10;
			coord.Y += 3;
			SetConsoleCursorPosition(hdle, coord);
			printf("학점을 100점 이하로 입력하세요\n");
		}
	}

	return;
}

void insert(student* phead, student* ptail) {
	int temp = 0;
	int i = 0;
	student* new_data;

	printdata(phead, ptail);
	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y += 3;
	SetConsoleCursorPosition(hdle, coord);
	printf("삽입하실 부분을 선택하세요: ");
	scanf("%d", &temp);

	for (i = 0; i < temp - 2; i++) {
		phead = phead->next;
	}

	new_data = createnode();
	new_data = inputdata();

	new_data->next = phead->next;
	new_data->prev = phead;
	phead->next = new_data;
	new_data->next->prev = new_data;

	return;
}

student* inputdata() {
	student* temp={ 0 };
	temp = createnode();

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y+=2;
	SetConsoleCursorPosition(hdle, coord);

	while (getchar() != '\n') break;
	printf("학번을 입력하세요: ");
	gets_s(temp->num, 128);

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y+=2;
	SetConsoleCursorPosition(hdle, coord);

	printf("이름을 입력하세요: ");
	gets_s(temp->name, 128);

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y+=2;
	SetConsoleCursorPosition(hdle, coord);

	while (1) {
		printf("학점을 입력하세요: ");
		scanf("%d", &temp->score);

		if (temp->score <= 100)
			break;
		else
			printf("학점을 100점 이하로 입력하세요\n");
	}

	return temp;
}

FILE* filesave(student* phead) {
	FILE* fp;
	char filename[128];
	char temp = 0;

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y = 6;
	SetConsoleCursorPosition(hdle, coord);

	while (getchar() != '\n');
	printf("파일명을 입력하세요: ");
	gets_s(filename, 128);
	fp = fopen(filename, "w+");

	while (1) {
		if (phead->next == NULL) {
			fprintf(fp, "%s\t%s\t%d", phead->num, phead->name, phead->score);

			break;
		}
		else
		{
			fprintf(fp, "%s\t%s\t%d\n", phead->num, phead->name, phead->score);

			phead = phead->next;
		}
	}

	fclose(fp);

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y+=3;
	SetConsoleCursorPosition(hdle, coord);

	printf("파일에 저장을 완료했습니다! 계속하시려면 아무키나 누르세요.");
	scanf("%c", &temp);

	
	return;
}

student* fileload(student** phead, student** ptail) {
	FILE* fp;
	char filename[128];
	student* new_data;
	char temp = 0;

	DirView(NULL);

	hdle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 10;
	coord.Y = 6;
	SetConsoleCursorPosition(hdle, coord);

	printf("파일 이름을 입력하세요: ");
	while (getchar() != '\n');
	gets_s(filename, 128);

	fp = fopen(filename, "r+");
	while (1) {
		if (feof(fp) != 0) break;
		new_data = createnode();
		
		fscanf(fp, "%s\t%s\t%d", &new_data->num, &new_data->name, &new_data->score);
		
		if (*ptail == NULL) {
			*ptail = new_data;
			*phead = *ptail;
			continue;
		}
		(*ptail)->next = new_data;
		new_data->prev = *ptail;
		
		*ptail = (*ptail)->next;
	}
	fclose(fp);
	
	coord.X = 10;
	coord.Y+=3;
	SetConsoleCursorPosition(hdle, coord);
	
	printf("파일을 정상적으로 불러왔습니다! 계속하시려면 아무키나 누르세요.");
	scanf("%c", &temp);

	return;
}

void DirView(const char* pstr) {
	intptr_t head;
	intptr_t result;
	char* data_list[2] = { "*.*","*.dat" };
	struct _finddata_t* data;
	struct tm* pdata_time;
	int i = 0;
	int row = 6;

	data = (struct _finddata_t*)malloc(sizeof(struct _finddata_t));

	while (i < sizeof(data_list) / sizeof(char*)) {
		head = 0;
		head =_findfirst(data_list[i], data);

		while (1) {
			if (head == -1) break;
			//TextView(15, row, " ");
			printf("%s\t\t %dbyte\t\t", data->name, data->size);
			pdata_time = localtime(&(data->time_access));
			printf("%d년 %d월 %d일 %d:%d에 마지막 엑세스\n", pdata_time->tm_year + 1900, pdata_time->tm_mon + 1, pdata_time->tm_mday, pdata_time->tm_hour, pdata_time->tm_min);

			result = _findnext(head, data);
			if (result == -1) break;

			row += 2;
		}

		_findclose(head);
		i++;
	}

	return;
}

void ui() {
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
	printf("학생 관리 프로그램\n");

	coord.X = 12;
	coord.Y = 12;
	SetConsoleCursorPosition(hdle, coord);

	printf("1.데이터 추가");

	coord.X = 27;
	coord.Y = 12;
	SetConsoleCursorPosition(hdle, coord);

	printf("2.데이터 출력");

	coord.X = 42;
	coord.Y = 12;
	SetConsoleCursorPosition(hdle, coord);

	printf("3.데이터 삭제");

	coord.X = 12;
	coord.Y = 15;
	SetConsoleCursorPosition(hdle, coord);

	printf("4.데이터 수정");

	coord.X = 27;
	coord.Y = 15;
	SetConsoleCursorPosition(hdle, coord);

	printf("5.데이터 삽입");

	coord.X = 42;
	coord.Y = 15;
	SetConsoleCursorPosition(hdle, coord);

	printf("6. 파일에 저장");

	coord.X = 12;
	coord.Y = 18;
	SetConsoleCursorPosition(hdle, coord);

	printf("7. 파일 불러오기");

	coord.X = 42;
	coord.Y = 18;
	SetConsoleCursorPosition(hdle, coord);

	printf("10.종료");


	coord.X = 12;
	coord.Y = 23;
	SetConsoleCursorPosition(hdle, coord);
	printf("select menu: ");

	return 0;
}