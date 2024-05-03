#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	char title[128];
	char time[128];
	int count;
	struct queue* head;
	struct queue* tail;
	struct queue* next;
	struct queue* back;
}queue;

queue* createnode();
void inputdata(queue* ptr);
queue* Enqueue(queue* data);
void printdata(queue* head, queue* tail);
queue* Dequeue(queue* head);

int main() {
	int menu = 0;
	queue* head=NULL;
	queue* tail=NULL;

	while (1) {
		printf("menu\n");
		printf("1.��ȭ ���� 2.���� ��Ȳ 3.�߱� 4.����\n");
		printf("����: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:  //��ȭ ����
			tail = Enqueue(tail);
			if (head == NULL) head = tail;
			break;
		case 2:  //���� ��Ȳ
			printdata(head, tail);
			break;
		case 3:  //�߱�
			head = Dequeue(head);
			break;
		case 4:  //����
			break;
		}

		if (menu == 4) break;
	}

	return 0;
}

queue* Dequeue(queue* head) {
	queue* temp;
	temp = createnode();

	if (head == NULL) {
		printf("���� ��Ȳ�� �����ϴ�.\n");
		return;
	}

	temp = head;
	head = head->next;

	printf("��ȭ Ƽ��\n");
	printf("��ȭ����: %s\n", temp->title);
	printf("��ȭ�ð�: %s\n", temp->time);
	printf("��ȭ�ο�: %d\n", temp->count);

	free(temp);
	head->back == NULL;

	return head;
}

void printdata(queue* head,queue* tail) {
	while (1) {

		if (head == NULL) {
			printf("���� ���� ��Ȳ�� �����ϴ�\n");
			return;
		}

		printf("��ȭ����: %s\t", head->title);
		printf("��ȭ�ð�: %s\t", head->time);
		printf("��ȭ�ο�: %d\n", head->count);

		if (head == tail) break;
		head = head->next;
	}

	return;
}

queue* Enqueue(queue* data) {
	queue* newdata;
	newdata = createnode();

	inputdata(newdata);

	if (data == NULL) data = createnode();
	data->next = newdata;
	newdata->back = data;

	return newdata;
}

queue* createnode() {
	queue *temp;

	temp = (queue*)malloc(sizeof(queue));

	temp->back = temp->next = temp->count = NULL;
	

	return temp;
}

void inputdata(queue* ptr) {

	while (getchar() != '\n');
	printf("��ȭ ������ �Է��ϼ���: ");
	gets_s(ptr->title, 128);

	printf("��ȭ �� �ð��� �Է��ϼ���: ");
	gets_s(ptr->time, 128);

	printf("�ο� ���� �Է��ϼ���: ");
	scanf("%d", &(ptr->count));

	return;
}