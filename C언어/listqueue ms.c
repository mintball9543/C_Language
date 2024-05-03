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
		printf("1.영화 예매 2.예매 현황 3.발권 4.종료\n");
		printf("선택: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:  //영화 예매
			tail = Enqueue(tail);
			if (head == NULL) head = tail;
			break;
		case 2:  //예매 현황
			printdata(head, tail);
			break;
		case 3:  //발권
			head = Dequeue(head);
			break;
		case 4:  //종료
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
		printf("예매 현황이 없습니다.\n");
		return;
	}

	temp = head;
	head = head->next;

	printf("영화 티켓\n");
	printf("영화제목: %s\n", temp->title);
	printf("영화시간: %s\n", temp->time);
	printf("영화인원: %d\n", temp->count);

	free(temp);
	head->back == NULL;

	return head;
}

void printdata(queue* head,queue* tail) {
	while (1) {

		if (head == NULL) {
			printf("현재 예매 현황이 없습니다\n");
			return;
		}

		printf("영화제목: %s\t", head->title);
		printf("영화시간: %s\t", head->time);
		printf("영화인원: %d\n", head->count);

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
	printf("영화 제목을 입력하세요: ");
	gets_s(ptr->title, 128);

	printf("영화 상영 시간을 입력하세요: ");
	gets_s(ptr->time, 128);

	printf("인원 수를 입력하세요: ");
	scanf("%d", &(ptr->count));

	return;
}