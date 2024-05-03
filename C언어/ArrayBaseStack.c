#include<stdio.h>
#include<stdlib.h>
#include "ArrayBaseStack.h"

char *inputdata();

int main(void)
{
	stack stack;
	stackinit(&stack);

	spush(&stack, inputdata());
	spush(&stack, inputdata());
	spush(&stack, inputdata());
	spush(&stack, inputdata());
	spush(&stack, inputdata());

	while (!sisempty(&stack))
		printf("%s\n", spop(&stack));

	return 0;
}

void stackinit(stack* pstack) {
	pstack->topindex = -1;
}

int sisempty(stack* pstack) {
	if (pstack->topindex == -1)
		return TRUE;
	else
		return FALSE;
}

void spush(stack* pstack, Data data)
{
	//pstack->stackarr[pstack->topindex]=data;
	
	pstack->topindex += 1;
	pstack->stackarr[pstack->topindex] = data;
}

Data spop(stack* pstack) {
	int ridx;

	if (sisempty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	ridx = pstack->topindex;
	pstack->topindex -= 1;

	return pstack->stackarr[ridx];
}

Data speek(stack* pstack) {
	if (sisempty(pstack)) {
		printf("Stack Memory Error!");;
		exit(-1);
	}

	return pstack->stackarr[pstack->topindex];
}

char * inputdata() {
	char *temp;

	temp = (char*)malloc(sizeof(char) * 128);
	printf("주소 입력: ");
	gets_s(temp, 128);

	return temp;
}