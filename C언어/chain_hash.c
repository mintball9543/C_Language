#include<stdio.h>
#include<stdlib.h>

typedef struct list {
	int value;
	struct list* next;
}list;

list* createnode();
list* addData(list* head,int pdata);
int makehash(int pkey);
void printdata(list* phead);


int main() {
	list* arr[513] = { 0 };
	int index = 0;
	int menu = 0;
	int value = 0;
	int i = 0;

	while (1) {
		printf("menu\n");
		printf("1.add 2.del 3.print 4.print all 5.exit\n");
		printf("select one: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			printf("input value: ");
			scanf("%d", &value);
			index = makehash(value);
			if (arr[index] == NULL)
				arr[index] = addData(arr[index], value);
			else
				addData(arr[index], value);
			break;
		case 2:
			break;
		case 3:
			printf("key value: ");
			scanf("%d", &index);
			printdata(arr[index]);
			break;
		case 4:
			for (i = 0; i < 513; i++) {
				if (arr[i] != NULL) {
					printdata(arr[i]);
				}
			}
			break;
		case 5:
			break;
		}

		if (menu == 5) break;
	}
}

void printdata(list* phead) {
	while (1) {
		if (phead == NULL) break;
		printf("%d ", phead->value);

		phead = phead->next;
	}

	return;
}

list* addData(list* head, int pdata) {
	list* temp;
	
	temp = createnode();
	temp->value = pdata;
	
	if (head == NULL) {
		
		head = temp;

		return head;
	}
	else {
		while (1) {
			if (head->next == NULL) break;
			head = head->next;
		}
		head->next = temp;
	}

	return head;
}

int makehash(int pkey) {
	pkey = pkey % 513;

	return pkey;
}

list* createnode() {
	list* temp;

	temp = malloc(sizeof(list));

	temp->next = temp->value = NULL;

	return temp;
}