#include<stdio.h>
#include<stdlib.h>

typedef struct list {
	int num;
	struct list* next;
}list;

list* createnode();
list* adddata(list *phead);
int inputdata();
void printdata(list* phead);
int searchdata(list* phead);
void insertdata(list* phead);
void deletedata(list* phead);
void modifydata(list* phead);


int main()
{
	list* phead=0;
	int menu = 0;

	while (1) {
		printf("[MENU]\n");
		printf("1.데이터추가 2.데이터삭제 3.수정 4.검색 5.삽입 6.출력 10.종료\n");
		printf("메뉴선택: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			if (phead == NULL)
				phead = adddata(phead);
			else
				adddata(phead);
			break;
		case 2:
			deletedata(phead);
			break;
		case 3:
			modifydata(phead);
			break;
		case 4:
			if (searchdata(phead))
				printf("값을 찾았습니다\n");
			else
				printf("값을 찾지 못했습니다\n");
			break;
		case 5:
			insertdata(phead);
			break;
		case 6:
			printdata(phead);
		case 10:
			break;
		default:
			printf("메뉴 선택 에러\n");
		}

		if (menu == 10) break;
	}

	return 0;
}

void modifydata(list* phead)
{
	int i = 0;
	int count = 0;

	printdata(phead);
	printf("몇번째 값을 수정하시겠습니까?: ");
	scanf("%d", &count);

	while (i < count - 1) {
		phead = phead->next;
		i++;
	}
	phead->num = inputdata();

	return;
}

void deletedata(list* phead)
{
	list* before;
	list* current;
	int count;
	int i = 0;

	printdata(phead);
	printf("몇번째 값을 삭제하시겠습니까?: ");
	scanf("%d", &count);

	current = phead;
	while (i < count-1) {
		before = current;
		current = current->next;
		i++;
	}
	before->next = current->next;
	free(current);

	return;
}

void insertdata(list* phead)
{
	list* before;
	list* current;
	list* newnode;
	int count;
	int i = 0;

	printdata(phead);
	printf("몇번째 값을 수정하시겠습니까?: ");
	scanf("%d", &count);

	newnode=createnode();
	newnode->num = inputdata();

	before = 0;
	current = phead;

	while (i<count-1) {
		before = current;
		current = current->next;
		i++;
	}

	before->next = newnode;
	newnode->next = current;


	return;
}

int searchdata(list* phead)
{
	int find = 0;
	int value = 0;

	printf("찾을 값을 입력하세요: ");
	scanf("%d", &value);

	while (1) {
		if (phead == NULL) break;
		if (phead->num == value)
			find = 1;
		phead = phead->next;
	}

	return find;
}

void printdata(list* phead) {
	while (1) {
		if (phead == NULL) break;

		printf("%d, ", phead->num);
		phead = phead->next;
	}
	printf("\n");
}

list* createnode()
{
	list *temp=0;

	temp = (list*)malloc(sizeof(list));

	temp->num = 0;
	temp->next = 0;

	return temp;
}

list* adddata(list *phead)
{
	list* input_node;


	input_node = createnode();

	input_node->num = inputdata();

	if (phead == NULL) {
		phead = input_node;
		return input_node;
	}

	while (1) {
		if (phead->next == NULL) break;
		phead = phead->next;
	}

	phead->next = input_node;


	return input_node;
}

int inputdata() {
	int num;
	
	printf("숫자를 입력하세요: ");
	scanf("%d", &num);



	return num;
}