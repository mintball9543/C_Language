#include<stdio.h>

int* creatememory(int psize);
int* input(int* pptr, int pindex);
void output(int* pptr, int pindex);
void modify(int* pptr, int pindex);
int* delete(int* pptr, int pindex);
int* insert(int* pptr, int pindex);
int copy(int* pptr, int pindex);
void paste(int* pptr, int pindex, int copydata);
void makefile(int* pptr, int pindex);
int fileload(int *pptr);
int* rsize(int *pptr,int pindex);
void CopyData(int* new_pptr,int* old_pptr,int pindex);
int* rrsize(int* pptr, int pindex);
int size=5;

int main()
{
	int* ptr;
	int index = 0;
	int menu = 0;
	int copy_data = 0;
	FILE* fptr;

	while (1)
	{
		printf("[Menu]\n");
		printf("1.memory create 2.input 3.output 4.modify 5.delete 6.insert 7.copy 8.paste 9.파일 생성 및 저장 10.파일 로드\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			ptr=creatememory(5);
			break;
		case 2:
			ptr=input(ptr, index);
			index++;
			break;
		case 3:
			output(ptr, index);
			break;
		case 4:
			modify(ptr, index);
			break;
		case 5:
			ptr=delete(ptr, index);
			index--;
			break;
		case 6:
			ptr=insert(ptr, index);
			index++;
			break;
		case 7:
			copy_data = copy(ptr, index);
			break;
		case 8:
			paste(ptr, index, copy_data);
			break;
		case 9:
			makefile(ptr,index);
			break;
		case 10:
			index=fileload(ptr);
			index--;
			break;
		}

		if (menu == 11) {
			free(ptr);
			break;
		}

	}




	return 0;
}

int* creatememory(int psize)
{
	int* temp;

	temp = malloc(sizeof(int) * psize);

	return temp;
}

int* rsize(int* pptr, int pindex)
{
	int* newarr;

	newarr = creatememory(pindex + 1);
	CopyData(newarr, pptr,pindex);

	return newarr;
}

int* rrsize(int* pptr, int pindex)
{
	int* newarr;

	newarr = creatememory(pindex-1);
	CopyData(newarr, pptr,pindex-1);

	return newarr;
}

void CopyData(int* new_pptr, int* old_pptr,int pindex)
{
	int i = 0;

	for (i = 0; i<pindex; i++)
	{
		new_pptr[i] = old_pptr[i];
	}
	free(old_pptr);

	return;
}


int* input(int* pptr, int pindex)
{
	int num = 0;
	int i = 0;

	printf("숫자를 입력하세요: ");
	scanf("%d", &num);
	
	//pptr[pindex] = num;
	if (pindex==size)
	{
		pptr=rsize(pptr, pindex);
		size++;
	}
	*(pptr + pindex) = num;

	return pptr;
}


void output(int* pptr, int pindex)
{
	int i = 0;
	for (i = 0; i < pindex; i++)
	{
		printf("%d\n", *(pptr+i));
	}


	return;
}

void modify(int* pptr, int pindex)
{
	int num = 0;
	int part = 0;
	output(pptr, pindex);

	printf("수정하실 부분을 선택하세요: ");
	scanf("%d", &part);
	part--;

	printf("숫자를 입력하세요: ");
	scanf("%d", &num);

	pptr[part] = num;

	return;
}

int* delete(int* pptr, int pindex)
{
	int part = 0;
	int i = 0;

	output(pptr, pindex);

	printf("삭제하실 부분을 선택하세요: ");
	scanf("%d", &part);
	part--;

	pptr[part] = 0;

	for (i = part; i < pindex; i++)
	{
		pptr[i] = pptr[i+ 1];
	}
	

	
	if (size > 5)
	{
		pptr=rrsize(pptr, pindex);
		size--;
	}
	return pptr;
}

int* insert(int* pptr, int pindex)
{
	int part = 0;
	int i = 0;
	int num = 0;

	output(pptr, pindex);

	printf("삽입할 부분이 몇번째입니까?: ");
	scanf("%d", &part);
	part--;
	
	if (pindex == size)
	{
		pptr = rsize(pptr, pindex);
		size++;
	}

	for (i = pindex; i > part; i--)
	{
		pptr[i] = pptr[i - 1];
	}

	printf("숫자를 입력하세요: ");
	scanf("%d", &num);

	pptr[part] = num;

	return pptr;
}

int copy(int* pptr, int pindex)
{
	int temp,part = 0;
	
	output(pptr, pindex);
	printf("복사할 부분을 선택하세요: ");
	scanf("%d", &part);
	part--;

	temp = pptr[part];

	return temp;
}


void paste(int* pptr, int pindex, int copydata)
{
	int part = 0;
	int check = 0;

	if (copydata == 0) printf("복사한 값이 없어 붙여넣을 수 없습니다");
	else
	{
		output(pptr, pindex);
		printf("몇번째에 붙여넣으시겠습니까?: ");
		scanf("%d", &part);
		part--;

		if (pptr[part] != 0)
		{
			printf("이미 값이 있는데 붙여넣을까요?\n1.yes 2.no: ");
			scanf("%d", &check);
			if (check)
				pptr[part] = copydata;
			else
				return;
		}
		else
			pptr[part] = copydata;
	}


	return;
}

void makefile(int* pptr, int pindex)
{
	FILE* fp;
	char filename[128] = { 0 };
	int i = 0;

	printf("파일명 입력: ");
	while (getchar() != '\n');
	gets_s(filename, 128);

	fp = fopen(filename, "w+");

	for(i=0;i<pindex;i++)
		fprintf(fp, "%d\t", pptr[i]);

	printf("파일에 저장 완료\n");

	fclose(fp);
	return;
}


int fileload(int* pptr)
{
	FILE* fp;
	char filename[128] = { 0 };
	int i = 0;

	printf("파일명 입력: ");
	while (getchar() != '\n');
	gets_s(filename, 128);
	fp = fopen(filename, "r+");

	for (i = 0;; i++)
	{
		if (feof(fp) != 0) break;
		fscanf(fp, "%d", &pptr[i]);
	}

	

	return i;
}
