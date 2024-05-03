#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<time.h>

struct Queue {
	int value;
	struct Queue* next;
	struct Queue* prev;
};

typedef struct Queue Queue;

Queue* front;
Queue* rear;

Queue* memalloc();
void enqueue(int value);
int dequeue();

unsigned int __stdcall QueueThread1(void* ptr);
unsigned int __stdcall QueueThread2(void* ptr);

int main() {
	int menu = 0;
	uintptr_t tid[2] = { 0 };

	tid[0] = _beginthreadex(0, 0, QueueThread1, NULL, 0, NULL);
	tid[1] = _beginthreadex(0, 0, QueueThread2, NULL, 0, NULL);

	_cwait(0, tid[0], 0);
	_cwait(0, tid[1], 0);

	return 0;
}

unsigned int __stdcall QueueThread1(void* ptr) {
	int in_value = 0;

	while (1) {
		printf("큐값 입력: ");
		scanf("%d", &in_value);
		enqueue(in_value);
	}

	return 0;
}

unsigned int __stdcall QueueThread2(void* ptr) {
	unsigned int wait_time = 0;
	int out_value = 0;

	wait_time = clock();
	while (1) {
		if (clock() - wait_time >= 1000) {
			out_value = dequeue();
			wait_time = clock();
			if (out_value != -1) {
				printf("\t\t\t\t\t\t\t 처리된 큐값: %d\n", out_value);
				out_value = -1;
			}
		}
	}

	return 0;
}

Queue* memalloc() {
	Queue* temp;

	temp = (Queue*)malloc(sizeof(Queue));
	temp->value = 0;
	temp->next = 0;
	temp->prev = 0;

	return temp;
}

void enqueue(int value) {
	Queue* node;

	node = memalloc();

	node->value = value;

	if (front == NULL) {
		rear = front = node;
	}
	else {
		node->prev = rear;
		rear->next = node;
		rear = node;
	}

	return;
}

int dequeue() {
	int value = 0;
	Queue* temp = 0;

	if (front == NULL) {
		printf("큐가 비었습니다.\n");
		return -1;
	}

	if (front == rear) {
		value = front->value;
		free(front);
		rear = front = NULL;
	}
	else {
		temp = front;
		front = front->next;
		value = temp->value;
		free(temp);
	}

	return value;
}