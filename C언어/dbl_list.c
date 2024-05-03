#include<stdio.h>

typedef struct list {
	int num;
	struct list* next;
	struct list* prev;
}list;

list* createnode();
list* addlist(list* ptail);
int inputdata();
void printdata(list* phead, list* ptail, int forward);
void modify(list* phead,list *ptail);
void insert(list* phead, list* ptail);
void delete(list* phead, list* ptail);

int main()
{
	list* head;
	list* tail;
	int menu=0;

	head = tail = NULL;

	while (1) {
		printf("[menu]\n");
		printf("1.add 2.insert 3.delete 4.modify 5.print 10.exit\n");
		printf("select one: ");

		scanf("%d", &menu);

		switch(menu) {
			case 1:
				tail=addlist(tail);
				if (head == NULL) {
					head = tail;
				}
				break;
			case 2:
				insert(head, tail);
				break;
			case 3:
				delete(head, tail);
				break;
			case 4:
				modify(head, tail);
				break;
			case 5:
				printdata(head, tail,0);
				break;
			
		}
		if (menu == 10) break;


	}

	return 0;
}

list* createnode() {
	list* temp;

	temp = malloc(sizeof(struct list));

	temp->next = temp->num = temp->prev = 0;

	return temp;
}

list* addlist(list* ptail) {
	list* new_node;

	//������ �� �Է�
	new_node = createnode();
	//tail�� NULL�� ��� ó��
	new_node->num = inputdata();
	if (ptail == NULL) {
		ptail = new_node;
		return new_node;
	}
	//tail�� NULL�� �ƴ� ���

	//next, prev����
	ptail->next = new_node;
	new_node->prev = ptail;

	return new_node;
}

void printdata(list* phead, list* ptail, int forward) {
	list* ptr;


	if (forward == 0) {
		printf("������ ���:1 // �����:2 :: ");
		scanf("%d", &forward);
	}

	if (forward == 1) {
		while (1) {
			printf("%d\n", phead->num);
			if (phead->next == NULL) break;
			phead = phead->next;
		}
	}
	else {
		while (1) {
			printf("%d\n", ptail->num);
			if (ptail->prev == NULL) break;
			ptail = ptail->prev;
		}
	}

	return;
}

void modify(list* phead, list* ptail)
{
	int loc = 0;
	int i = 0;

	printdata(phead, ptail, 1);
	printf("���° ���� �����Ͻðڽ��ϱ�?: ");
	scanf("%d", &loc);
	

	while (1) {
		if (i < loc - 1) {
			phead = phead->next;
			i++;
		}
		else break;
	}

	phead->num = inputdata();

	return;
}

void insert(list* phead, list* ptail)
{
	int loc = 0;
	int i = 0;
	list* new_node;

	printdata(phead, ptail, 1);
	printf("���°�� ���� �����Ͻðڽ��ϱ�?: ");
	scanf("%d", &loc);

	while (1) {
		if (i < loc-2) {
			phead = phead->next;
			i++;
		}
		else break;
	}

	new_node = createnode();
	new_node->num = inputdata();

	new_node->next = phead->next;
	phead->next = new_node;
	new_node->next->prev = new_node;
	new_node->prev = phead;

	return;
}

void delete(list* phead, list* ptail)
{
	int loc = 0;
	int i = 0;

	printdata(phead, ptail, 1);
	printf("���° ���� �����Ͻðڽ��ϱ�?: ");
	scanf("%d", &loc);

	while (1)
	{
		if (i < loc - 1) {
			phead = phead->next;
			i++;
		}
		else break;
	}

	phead->prev->next = phead->next;
	phead->next->prev = phead->prev;

	free(phead);

	return;
}

int inputdata()
{
	int num=0;


	printf("���� �Է��ϼ���: ");
	scanf("%d", &num);


	return num;
}