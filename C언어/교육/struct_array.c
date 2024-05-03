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
		printf("1.입력 2.출력 3.수정 4.삭제 10.종료\n");
		printf("메뉴 선택: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			while (getchar() != '\n');
			printf("이름을 입력하세요: ");
			gets_s(data[idx].name, 20);
			
			printf("나이를 입력하세요: ");
			scanf("%d", &data[idx].age);
			
			while (getchar() != '\n');
			printf("전화번호를 입력하세요: ");
			gets_s(data[idx].phone, 20);
			
			idx++;
			break;
		case 2:
			printf("---------------------------------\n");
			for (i = 0; i < idx; i++)
				printf("이름: %s / 나이: %d / 전화번호: %s\n", data[i].name, data[i].age, data[i].phone);
			printf("---------------------------------\n");
			break;
		case 3:
			printf("---------------------------------\n");
			for (i = 0; i < idx; i++)
				printf("이름: %s / 나이: %d / 전화번호: %s\n", data[i].name, data[i].age, data[i].phone);
			printf("---------------------------------\n");

			printf("몇 번째 값을 수정하시겠습니까?: ");
			scanf("%d", &temp);

			while (getchar() != '\n');
			printf("이름을 입력하세요: ");
			gets_s(data[temp-1].name, 20);

			printf("나이를 입력하세요: ");
			scanf("%d", &data[temp-1].age);

			while (getchar() != '\n');
			printf("전화번호를 입력하세요: ");
			gets_s(data[temp-1].phone, 20);
			break;
		case 4:
			printf("---------------------------------\n");
			for (i = 0; i < idx; i++)
				printf("이름: %s / 나이: %d / 전화번호: %s\n", data[i].name, data[i].age, data[i].phone);
			printf("---------------------------------\n");

			printf("몇 번째 값을 삭제하시겠습니까?: ");
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