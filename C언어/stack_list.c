#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int num;
	struct stack* next;
	struct stack* prev;
}stack;

stack* createnode();
stack* push(stack* psp);
int pop(stack* pbp, stack** psp);

int main()
{
	stack* bp;
	stack* sp;
	int menu = 0;
	bp = sp = NULL;
	while (1) {
		printf("[menu]\n");
		printf("1.push 2.pop 3.exit\n");
		printf("select one: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			sp = push(sp);
			if (bp == NULL) bp = sp;
			break;
		case 2:
			//while (1) {
				printf("%d\n", pop(bp, &sp));
				//if (bp == sp) break;
			//}
			break;
		case 3:
			break;
		default:
			printf("menu error\n");
		}
		if (menu == 3) break;
	}

	return 0;
}

stack* createnode() {
	stack* temp;

	temp = (stack *)malloc(sizeof(stack));

	temp->next = temp->prev = temp->num = 0;

	return temp;
}

stack* push(stack* psp) {
	stack* new_node;
	int i = 0;

	new_node = createnode();

	printf("값을 입력하세요: ");
	scanf("%d", &new_node->num);
	
	if (psp == NULL) {
		return new_node;
	}

	psp->next = new_node;
	new_node->prev = psp;


	return new_node;
}

int pop(stack* pbp, stack** psp) {
	int temp=0;
	stack* prev_node;
	//pbp와 psp와 같으면 error
	if (pbp == *psp) {
		printf("error");
		exit(-1);
	}
	//psp가 가리키는 위치의 노드 값을 temp에 저장
	temp = (*psp)->num;
	//psp노드 제거 후 이전 노드로 이동
	prev_node = *psp;
	*psp = (*psp)->prev;

	free(prev_node);
	(*psp)->next = NULL;

	return temp;
}