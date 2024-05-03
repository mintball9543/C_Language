#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person {
	char name[128];
	char num[128];
	struct person* next;
}person;

person* createnode();
person* addData(person* phead,char* name);
int key(person* key);
void printdata(person* phead);
person* deletedata(person* phead);
person* inputdata();

int main() {
	int menu = 0;
	int idx = 0;
	int i = 0;
	char t_key[128] = { 0 };
	person* arr[128] = { 0 };

	while (1) {
		printf("메뉴\n");
		printf("1.전화번호 추가 2.전화번호 삭제 3.전화번호 찾기 4.모든 전화번호 출력  5.종료\n");
		printf("메뉴선택: ");
		scanf("%d", &menu);
		switch (menu) {
		case 1: //추가
			while (getchar() != '\n');
			printf("이름을 입력하세요: ");
			gets_s(t_key, 128);
			idx = key(t_key);

			if (arr[idx] == NULL)
				arr[idx] = addData(arr[idx], t_key);
			else
				addData(arr[idx], t_key);
			break;
		case 2: //삭제
			while (getchar() != '\n');
			printf("이름을 입력하세요: ");
			gets_s(t_key, 128);
			idx = key(t_key);
			arr[idx] = deletedata(arr[idx]);
			break;
		case 3: //키값 번호 출력
			while (getchar() != '\n');
			printf("이름을 입력하세요: ");
			gets_s(t_key, 128);
			idx = key(t_key);

			printdata(arr[idx]);
			break;
		case 4: //모든 번호 출력
			for (i = 0; i < 128; i++) {
				if (arr[i] != NULL)
					printdata(arr[i]);
			}
			break;
		case 5: //종료
			break;
		}

		if (menu == 5) break;
	}
}

person* createnode() {
	person* temp;
	int i = 0;
	temp = malloc(sizeof(person));
	
	for (i = 0; i < 128; i++) {
		temp->name[i] = NULL;
		temp->num[i] = NULL;
	}

	temp->next = NULL;

	return temp;
}

person* addData(person* phead,char* name) {
	person* newnode;
	newnode = createnode();

	strcpy(newnode->name, name);
	printf("전화번호를 입력하세요: ");
	gets_s(newnode->num, 128);
	key(newnode->name);

	if (phead == NULL) {
		phead = newnode;
		return phead;
	}

	while (1) {
		if (phead->next == NULL) break;
		phead = phead->next;
	}
	phead->next = newnode;

	return phead;
}

int key(person* key) {
	int i = 0;
	int sum = 0;

	while (1) {
		if (key->name[i] == NULL) break;
		sum += key->name[i];
		i++;
	}

	return sum % 128;
}

void printdata(person* phead) {
	while (1) {
		if (phead == NULL) break;

		printf("%s\t", phead->name);
		printf("%s\n", phead->num);

		phead = phead->next;
	}
	printf("\n");
	return;
}

person* deletedata(person* phead) {
	person* before;
	person* current;
	int temp = 0;
	int i = 0;

	printdata(phead);
	printf("몇번째 데이터를 삭제할까요? ");
	scanf("%d", &temp);

	if (temp == 1) {
		current = phead;
		phead = phead->next;
		free(current);

		return phead;
	}

	for (i = 0; i < temp - 2; i++) {
		phead = phead->next;
	}
	before = phead;
	phead = phead->next;
	current = phead;

	before->next = current->next;

	free(current);

	return;
}

person* inputdata() {
	person* temp;

	printf("이름을 입력하세요: ");
	gets_s(temp->name, 128);

	printf("전화번호를 입력하세요: ");
	gets_s(temp->num, 128);

	return temp;
}