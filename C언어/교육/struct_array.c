#include<stdio.h>

typedef struct {
	char name[20];
	int age;
	char phone[20];
}person;

int main() {
	int menu = 0;
	person data[126];
	int idx = 0;
	int i = 0;
	int temp = 0;

	while (1) {
		printf("1.�Է� 2.��� 3.���� 4.���� 10.����\n");
		printf("�޴� ����: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			while (getchar() != '\n');
			printf("�̸��� �Է��ϼ���: ");
			gets_s(data[idx].name, 20);
			
			printf("���̸� �Է��ϼ���: ");
			scanf("%d", &data[idx].age);
			
			while (getchar() != '\n');
			printf("��ȭ��ȣ�� �Է��ϼ���: ");
			gets_s(data[idx].phone, 20);
			
			idx++;
			break;
		case 2:
			printf("---------------------------------\n");
			for (i = 0; i < idx; i++)
				printf("�̸�: %s / ����: %d / ��ȭ��ȣ: %s\n", data[i].name, data[i].age, data[i].phone);
			printf("---------------------------------\n");
			break;
		case 3:
			printf("---------------------------------\n");
			for (i = 0; i < idx; i++)
				printf("�̸�: %s / ����: %d / ��ȭ��ȣ: %s\n", data[i].name, data[i].age, data[i].phone);
			printf("---------------------------------\n");

			printf("�� ��° ���� �����Ͻðڽ��ϱ�?: ");
			scanf("%d", &temp);

			while (getchar() != '\n');
			printf("�̸��� �Է��ϼ���: ");
			gets_s(data[temp-1].name, 20);

			printf("���̸� �Է��ϼ���: ");
			scanf("%d", &data[temp-1].age);

			while (getchar() != '\n');
			printf("��ȭ��ȣ�� �Է��ϼ���: ");
			gets_s(data[temp-1].phone, 20);
			break;
		case 4:
			printf("---------------------------------\n");
			for (i = 0; i < idx; i++)
				printf("�̸�: %s / ����: %d / ��ȭ��ȣ: %s\n", data[i].name, data[i].age, data[i].phone);
			printf("---------------------------------\n");

			printf("�� ��° ���� �����Ͻðڽ��ϱ�?: ");
			scanf("%d", &temp);

			for (i = temp-1; i < idx; i++) {
				sprintf(data[i].name, "%s", data[i + 1].name);
				data[i].age = data[i + 1].age;
				sprintf(data[i].phone, "%s", data[i + 1].phone);
			}
			idx--;
			break;
		default:
			break;
		}
		if (menu == 10) break;
	}

	return 0;
}