#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef char* Data;

typedef struct _arraystack {
	Data stackarr[STACK_LEN];
	int topindex;
}arraystack;

typedef arraystack stack;

void stackinit(stack* pstack);
int sisempty(stack* pstack);

void spush(stack* pstack, Data data);
Data spop(stack* pstack);
Data speek(stack* pstack);

#endif