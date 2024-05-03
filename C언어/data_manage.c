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
		printf("1. 데이터추가 2. 데이터 삭제 3. 데이터 수정 4. 정렬수행 5. 최대값확인\n");
		printf("6. 최소값확인 7. 합계 계산 8. 평균계산 9. 데이터 출력\n");
		printf("10. 파일열기 11. 파일저장 12. 종료\n");

		printf("메뉴선택: ");
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
			printf("최대값: %d\n", getmax(data_arr, sorting, index));
			break;
		case 6:
			printf("최소값: %d\n", getmin(data_arr, sorting, index));
			break;
		case 7:
			printf("합계값: %d\n", getsum(data_arr, index));
			break;
		case 8:
			printf("평균값: %f\n", getavg(data_arr, index));
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
			printf("메뉴선택 에러\n");
		}

		if (menu == 12) {
			printf("프로그램을 종료합니다.\n");
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
	printf("%d번째 점수 입력:",pidx+1);
	scanf("%d",ptr+pidx);

	return;
}