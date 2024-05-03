#include<stdio.h>

struct node {
	int value;
	int flag;
};

typedef struct node node;

int makenode(node* pbtree, int ppindex);
int createdata();
int preview(node* pbtree);
void middleview(node* pbree);
void outview(node* pbtree);
int search(node* pbtree, int value);

#define LEFT_IN(pindex) (pindex+1)*2-1
#define RIGHT_IN(pindex) (pindex+1)*2

int tree_size = 0;

int main() {
	node btree[256] = { 0 };
	int menu = 0;
	int pos = 0;
	int order = 0;

	while (1) {
		printf("[MENU]\n");
		printf("1.데이터 추가 2.데이터 출력 3.종료\n");
		printf("메뉴선택: ");
		scanf("%d", &menu);

		if (menu == 1) {
			if (tree_size == 0)
				makenode(btree, 0); //루트노드만 존재할 때 수행될 내용
			else {
				printf("추가할 데이터 위치 선택: ");
				preview(btree);
				printf("\n");
				scanf("%d", &pos);
				if (makenode(btree, search(btree, pos)) == -1) {
					printf("현재 노드의 좌우 데이터가 다차서 추가할 수 없습니다.\n");
					continue;
				}
			}
			tree_size++;
		}
		if (menu == 2) {
			printf("출력할 방법 선택 1)전위출력 2)중위출력 3)후위출력\n");
			printf("선택: ");
			scanf("%d", &order);
			if (order == 1) preview(btree);
			else if (order == 2) middleview(btree);
			else if (order == 3) outview(btree);
			else
				printf("출력선택 에러");
			printf("\n");
		}
		if (menu == 3) break;
	}

	return 0;
}

int search(node* pbtree, int value) {
	int index = 0;
	int arr[64] = { 0 };
	int pi = 0;
	int i = 0;

	while (1) {
		if (pbtree[index].flag == 0) {
			if (pbtree[index].value == value)
				break;
			pbtree[index].flag = 1;
		}

		if (pbtree[(index + 1) * 2 - 1].value != 0 && pbtree[(index + 1) * 2 - 1].flag == 0){
				arr[pi++] = index;
				index = (index + 1) * 2 - 1;
				continue;
		}

		if (pbtree[(index + 1) * 2].value != 0 && pbtree[(index + 1) * 2].flag == 0) {
			arr[pi++] = index;
			index = (index + 1) * 2;
			continue;
		}

		if (pi == 0) break;
		index = arr[--pi];
	}

	for (i = 0; i < tree_size; i++)
		pbtree[i].flag = 0;

	return index;
}

void outview(node* pbtree) {
	int index = 0;
	int stack[64] = { 0 };
	int sp = 0;
	int i = 0;

	while (1) {
		if (pbtree[LEFT_IN(index)].value != 0 && pbtree[LEFT_IN(index)].flag == 0) {
			stack[sp++] = index;
			index = LEFT_IN(index);
			continue;
		}
		if (pbtree[RIGHT_IN(index)].value != 0 && pbtree[RIGHT_IN(index)].flag == 0) {
			stack[sp++] = index;
			index = RIGHT_IN(index);
			continue;
		}
		if (pbtree[index].flag == 0) {
			printf("%d, ", pbtree[index].value);
			pbtree[index].flag = 1;
		}
		if (sp == 0) break;
		index = stack[--sp];
	}

	for (i = 0; i < tree_size; i++)
		pbtree[i].flag = 0;

	return;
}

void middleview(node* pbtree) {
	int index = 0;
	int stack[64] = { 0 };
	int sp = 0;
	int i = 0;

	while (1) {
		if (pbtree[LEFT_IN(index)].value != 0 && pbtree[LEFT_IN(index)].flag == 0) {
			stack[sp++] = index;
			index = LEFT_IN(index);
			continue;
		}		
		
		if (pbtree[index].flag == 0) {
			printf("%d, ", pbtree[index].value);
			pbtree[index].flag = 1;
		}

		if (pbtree[RIGHT_IN(index)].value != 0 && pbtree[RIGHT_IN(index)].flag == 0) {
			stack[sp++] = index;
			index = RIGHT_IN(index);
			continue;
		}
		if (sp == 0) break;
		index = stack[--sp];
	}

	for (i = 0; i < tree_size; i++)
		pbtree[i].flag = 0;

	return;
}

int preview(node* pbtree) {
	int index = 0;
	int arr[64] = { 0 };
	int pi = 0;
	int i = 0;

	while (1) {
		if (pbtree[index].flag == 0) {
			printf("%d, ", pbtree[index].value);
			pbtree[index].flag = 1;
		}

		if (pbtree[(index+1)*2-1].value != 0 && pbtree[(index+1)*2-1].flag == 0) {
			arr[pi++] = index;
			index = (index + 1) * 2 - 1;
			continue;
		}

		if (pbtree[(index+1)*2].value != 0 && pbtree[(index+1)*2].flag == 0) {
			arr[pi++] = index;
			index = (index + 1) * 2;
			continue;
		}
		if (pi == 0) break;
		index = arr[--pi];
	}

	for (i = 0; i < tree_size; i++)
		pbtree[i].flag = 0;

	return 0;
}

int makenode(node* pbtree, int ppindex) {
	int temp = 0;
	int i = 0;
	int index = 0;

	temp = createdata();

	if (tree_size == 0) {
		pbtree[ppindex].value = temp;
		return 0;
	}

	index = (ppindex + 1) * 2 - 1;
	if (pbtree[index].value == 0) {
		pbtree[index].value = temp;
		return 0;
	}

	index = RIGHT_IN(ppindex);
	if (pbtree[index].value == 0) {
		pbtree[index].value = temp;
		return 0;
	}

	return -1;
}

int createdata() {
	int value = 0;

	printf("데이터 입력: ");
	scanf("%d", &value);

	return value;
}