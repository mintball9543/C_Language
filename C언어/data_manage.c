#include<stdio.h>

void inputscore(int* ptr,int pidx);
void sort(int* ptr,int pidx);
int getmax(int* ptr, int psort,int pidx);
int getmin(int* ptr, int psort,int pidx);
int getsum(int* ptr,int pidx);
float getavg(int* ptr,int pidx);
void printdata(int* ptr,int pidx);

int main()
{
	int data_arr[128] = { 0 };
	int menu = 0;
	int index = 0;
	int sorting = 0;

	while (1) {
		printf("[menu]\n");
		printf("1. �������߰� 2. ������ ���� 3. ������ ���� 4. ���ļ��� 5. �ִ밪Ȯ��\n");
		printf("6. �ּҰ�Ȯ�� 7. �հ� ��� 8. ��հ�� 9. ������ ���\n");
		printf("10. ���Ͽ��� 11. �������� 12. ����\n");

		printf("�޴�����: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			inputscore(data_arr, index++);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			sort(data_arr, index);
			sorting = 1;
			break;
		case 5:
			printf("�ִ밪: %d\n", getmax(data_arr, sorting, index));
			break;
		case 6:
			printf("�ּҰ�: %d\n", getmin(data_arr, sorting, index));
			break;
		case 7:
			printf("�հ谪: %d\n", getsum(data_arr, index));
			break;
		case 8:
			printf("��հ�: %f\n", getavg(data_arr, index));
			break;
		case 9:
			printdata(data_arr, index);
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		default:
			printf("�޴����� ����\n");
		}

		if (menu == 12) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
	}

	return 0;
}

int getsum(int* ptr, int pidx) {
	int i = 0;
	int sum = 0;

	for (i = 0; i < pidx; i++) {
		sum += ptr[i];
	
	}
	return sum;
}

float getavg(int* ptr, int pidx) {
	int i = 0;
	float avg = 0.0f;
	int sum = 0;

	for (i = 0; i < pidx; i++) {
		sum += ptr[i];
	}

	avg = (float)sum / (float)pidx;

	return avg;
}

int getmax(int* ptr, int psort, int pidx) {
	int max_value = 0;
	int i = 0;

	if (psort == 0) {
		for (i = 0, max_value = ptr[0]; i < pidx; i++) {
			if (max_value < ptr[i]) {
				max_value = ptr[i];
			}
		}
	}
	else
	{
		max_value = ptr[pidx - 1];
	}
	return max_value;
}


int getmin(int* ptr, int psort, int pidx) {
	int min_value = 0;
	int i = 0;

	if (psort == 0) {
		for (i = 0, min_value = ptr[0]; i < pidx; i++) {
			if (min_value < ptr[i]) {
				min_value = ptr[i];
			}
		}
	}
	else
	{
		min_value = ptr[0];
	}
	return min_value;
}


void sort(int* ptr, int pidx)
{
	int i = 0;
	int j = 0;
	int temp = 0;


	for (i = 0; i < pidx; i++) {
		for (j = i + 1; j < pidx; j++) {
			if (ptr[i] > ptr[j]) {
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
	return;
}

void printdata(int* ptr, int pidx) {
	int i = 0;

	for (i = 0; i < pidx; i++)
		printf("%d : %d\n", i + 1, ptr[i]);

	return;
}

void inputscore(int* ptr, int pidx) {
	printf("%d��° ���� �Է�:",pidx+1);
	scanf("%d",ptr+pidx);

	return;
}