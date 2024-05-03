#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"CircularQueue.h"

#define CUS_COME_TERM 15

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2
#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

int main(void) {
	int makeproc = 0;
	int cheorder = 0, bulorder = 0, duborder = 0;
	int sec;

	Queue que;

	QueueInit(&que);
	srand(time(NULL));

	for (sec = 0; sec < 3600; sec++) {
		if (sec % CUS_COME_TERM == 0) {
			switch (rand() % 3) {
			case CHE_BUR:
				Enqueue(&que, CHE_TERM);
				cheorder += 1;
				break;
			case BUL_BUR:
				Enqueue(&que, BUL_TERM);
				bulorder += 1;
				break;
			case DUB_BUR:
				Enqueue(&que, DUB_TERM);
				duborder += 1;
				break;
			}
		}

		if (makeproc <= 0 && !QIsEmpty(&que))
			makeproc = Dequeue(&que);

		makeproc--;
	}

	printf("Simulation Report!\n");
	printf(" - Cheese burger: %d\n", cheorder);
	printf(" - Bulgogi burger: %d\n", bulorder);
	printf(" - Double burger: %d\n", duborder);
	printf(" - Waiting room size: %d\n", QUE_LEN);
	return 0;
}