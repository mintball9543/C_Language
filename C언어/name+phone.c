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
		printf("�޴�\n");
		printf("1.��ȭ��ȣ �߰� 2.��ȭ��ȣ ���� 3.��ȭ��ȣ ã�� 4.��� ��ȭ��ȣ ���  5.����\n");
		printf("�޴�����: ");
		scanf("%d", &menu);
		switch (menu) {
		case 1: //�߰�
			while (getchar() != '\n');
			printf("�̸��� �Է��ϼ���: ");
			gets_s(t_key, 128);
			idx = key(t_key);

			if (arr[idx] == NULL)
				arr[idx] = addData(arr[idx], t_key);
			else
				addData(arr[idx], t_key);
			break;
		case 2: //����
			while (getchar() != '\n');
			printf("�̸��� �Է��ϼ���: ");
			gets_s(t_key, 128);
			idx = key(t_key);
			arr[idx] = deletedata(arr[idx]);
			break;
		case 3: //Ű�� ��ȣ ���
			while (getchar() != '\n');
			printf("�̸��� �Է��ϼ���: ");
			gets_s(t_key, 128);
			idx = key(t_key);

			printdata(arr[idx]);
			break;
		case 4: //��� ��ȣ ���
			for (i = 0; i < 128; i++) {
				if (arr[i] != NULL)
					printdata(arr[i]);
			}
			break;
		case 5: //����
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
	printf("��ȭ��ȣ�� �Է��ϼ���: ");
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
	printf("���° �����͸� �����ұ��? ");
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

	printf("�̸��� �Է��ϼ���: ");
	gets_s(temp->name, 128);

	printf("��ȭ��ȣ�� �Է��ϼ���: ");
	gets_s(temp->num, 128);

	return temp;
}