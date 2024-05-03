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
		printf("1.�������߰� 2.�����ͻ��� 3.���� 4.�˻� 5.���� 6.��� 10.����\n");
		printf("�޴�����: ");
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
				printf("���� ã�ҽ��ϴ�\n");
			else
				printf("���� ã�� ���߽��ϴ�\n");
			break;
		case 5:
			insertdata(phead);
			break;
		case 6:
			printdata(phead);
		case 10:
			break;
		default:
			printf("�޴� ���� ����\n");
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
	printf("���° ���� �����Ͻðڽ��ϱ�?: ");
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
	printf("���° ���� �����Ͻðڽ��ϱ�?: ");
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
	printf("���° ���� �����Ͻðڽ��ϱ�?: ");
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

	printf("ã�� ���� �Է��ϼ���: ");
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
	
	printf("���ڸ� �Է��ϼ���: ");
	scanf("%d", &num);



	return num;
}