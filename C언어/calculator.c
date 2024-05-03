#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void* stack[256] = { 0 };

int bp = 0;
int sp = 0;

void push(void* ptr);
void* Pop();
void SaveBP();
void* RestoreBP();
char* CreateString(const char* pstr);
char* ConvertPost(const char* pstr);
void ViewPostData(const char* pstr1, const char* pstr2);
int ConvertDecimal(const char* pstr);
int Calcurator(const char* pstr);

int main() {
	char* user_data = 0;
	char buffer[256] = { 0 };
	char* post_data = 0;
	int menu = 0;
	int i = 0;
	int result = 0;

	while (1) {
		printf("[MENU]\n");
		printf("1.계산식 입력 2.후위식 변환 3.후위식보기 4.계산하기 5.기록 6.종료\n");
		printf("메뉴선택: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			printf("계산식 입력: ");
			while (getchar() != '\n');
			gets_s(buffer, 256);
			user_data = CreateString(buffer);
			push(user_data);
			break;
		case 2:
			SaveBP();
			post_data = ConvertPost(user_data);
			RestoreBP();
			break;
		case 3:
			ViewPostData(user_data,post_data);
			break;
		case 4:
			SaveBP();
			result = Calcurator(post_data);
			RestoreBP();
			printf("%s=%d\n", user_data, result);
			break;
		case 5:
			for (i = 0; i < sp; i++) {
				printf("%d. %s\n\n", i + 1, (char*)(stack[i]));
			}
			break;
		case 6:
			break;
		default:
			printf("메뉴 선택 오류\n");
		}
		if (menu == 6) break;
	}

	return 0;
}

int Calcurator(const char* pstr) {
	int result = 0;
	int convert = 0;
	char buffer[64] = { 0 };
	int i = 0;
	int index = 0;
	int count = 0;
	int* num_ptr = 0;
	int num1 = 0;
	int num2 = 0;
	char op = 0;

	while (1) {
		if (pstr[index] == 0) break;
		if (pstr[index] != '*' && pstr[index] != '+' && pstr[index] != '-' && pstr[index] != '/') {
			count = pstr[index];
			index++;
			for (i = 0; i < count; i++) {
				buffer[i] = pstr[index++];
			}
			buffer[i] = 0;
			convert = ConvertDecimal(buffer);
			num_ptr = (int*)malloc(sizeof(int));
			*num_ptr = convert;
			push(num_ptr);
		}
		else {
			op = pstr[index++];
			num_ptr = (int*)Pop();
			num1 = *num_ptr;
			free(num_ptr);
			num_ptr = (int*)Pop();
			num2 = *num_ptr;
			free(num_ptr);
			switch (op) {
			case '+':
				result = num1 + num2;
				break;
			case '-':
				result = num1 - num2;
				break;
			case '*':
				result = num1 * num2;
				break;
			case '/':
				result = num1 / num2;
				break;
			}
			num_ptr = (int*)malloc(sizeof(int));
			*num_ptr = result;
			push(num_ptr);
		}
	}
	num_ptr = (int*)Pop();
	result = *num_ptr;
	free(num_ptr);

	return result;
}

int ConvertDecimal(const char* pstr) {
	int result = 0;
	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 0; i < strlen(pstr); i++) {
		temp = pstr[i] & 0xCF;
		for (j = strlen(pstr) - i - 1; j > 0; j--) {
			temp = temp * 10;
		}
		result += temp;
	}

	return result;
}

void ViewPostData(const char* pstr1, const char* pstr2) {
	char buffer[512] = { 0 };
	int index = 0;
	int count = 0;
	int i = 0;
	int end = 0;

	while (1) {
		if (pstr2[index] == 0) break;
		if (pstr2[index] != '*' && pstr2[index] != '/' && pstr2[index] != '+' && pstr2[index] != '-') {
			count = pstr2[index];
			index++;
			for (end = i + count; i < end; i++) {
				buffer[i] = pstr2[index++];
			}
		}
		else {
			buffer[i++] = pstr2[index++];
		}
	}

	printf("입력된 계산식(중위표현: %s\n", pstr1);
	printf("변환된 후위식: %s\n", buffer);

	return;
}

char* ConvertPost(const char* pstr) {
	char* post_ptr;
	char buffer[512] = { 0 };
	int i = 0;
	int len = 0;
	int num_start = 0;;
	int num_end = 0;
	int post_i = 0;
	char temp;
	char* data_mem;

	while (1) {
		if (i > strlen(pstr)) break;

		if (pstr[i] >= '0' && pstr[i] <= '9') {
			if (len == 0)
				num_start = i;
			len++;
		}
		else {
			if (len != 0) {
				buffer[post_i++] = len;
				for (num_end = num_start + len; num_start < num_end; num_start++) {
					buffer[post_i++] = pstr[num_start];
				}
				len = 0;
			}
			if (pstr[i] == NULL) break;

			if (pstr[i] == '(') {
				data_mem = (char*)malloc(sizeof(char));
				*data_mem = pstr[i];
				push(data_mem);
			}
			else if (pstr[i] == ')') {
				while (1) {
					data_mem = (char*)Pop();
					temp = *data_mem;
					free(data_mem);
					if (temp == '(')break;
					buffer[post_i++] = temp;
				}
			}
			else {
				data_mem = (char*)Pop();
				if (data_mem != 0)
					temp = *data_mem;
				else
					temp = 0;
				push(data_mem);
				if (temp != '+' && temp != '-' && temp != '*' && temp != '/') {
					data_mem = (char*)malloc(sizeof(char));
					*data_mem = pstr[i];
					push(data_mem);
				}
				else {
					if (pstr[i] == '*' || pstr[i] == '/') {
						if (temp == '+' || temp == '-') {
							data_mem = (char*)malloc(sizeof(char));
							*data_mem = pstr[i];
							push(data_mem);
						}
						else if (temp == '*' || temp == '/') {
							data_mem = (char*)Pop();
							buffer[post_i++] = *data_mem;
							free(data_mem);
							data_mem = (char*)malloc(sizeof(char));
							*data_mem = pstr[i];
							push(data_mem);
						}
					}
					else if (pstr[i] == '+' || pstr[i] == '-') {
						data_mem = (char*)Pop();
						buffer[post_i++] = *data_mem;
						free(data_mem);
						data_mem = (char*)malloc(sizeof(char));
						*data_mem = pstr[i];
						push(data_mem);
					}
				}
			}
		}
		i++;
	}

	while (1) {
		data_mem = (char*)Pop();
		if (data_mem == NULL) break;
		buffer[post_i++] = *data_mem;
		free(data_mem);
	}

	post_ptr = CreateString(buffer);

	return post_ptr;
}

char* CreateString(const char* pstr) {
	char* temp;

	temp = (char*)malloc(strlen(pstr) + 1);
	if (temp != 0) {
		strncpy_s(temp, strlen(pstr) + 1, pstr, strlen(pstr));
		temp[strnlen_s(pstr, 255) + 1] = 0;
	}

	return temp;
}

void push(void* ptr) {
	if (sp == 256) {
		printf("Stack Overflow\n");
		return;
	}
	stack[sp++] = ptr;

	return;
}

void* Pop() {
	if (bp == sp) {
		printf("Stack Underflow\n");
		return NULL;
	}

	return stack[--sp];
}

void SaveBP() {
	stack[sp++] = (int)bp;
	bp = sp;

	return;
}

void* RestoreBP() {
	sp = bp - 1;
	bp = (int)stack[bp - 1];

	return NULL;
}