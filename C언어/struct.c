#include<stdio.h>
#include<stdlib.h>


typedef struct test {
	int num;
	char str[128];
	struct test* ptr;
}test;

int main()
{
	/*test temp1 = { 10,"test1",0 };
	test temp2 = { 20,"test2",0 };
	test temp3 = { 30,"test3",0 };
	test temp4 = { 40,"test4",0 };
	test* pointer;

	temp1.ptr = &temp2;
	temp2.ptr = &temp3;
	temp3.ptr = &temp4;

	printf("%d / %d / %d\n", temp2.num, temp1.ptr->num, temp2.num);
	printf("%d / %d / %d\n", temp3.num, temp1.ptr->ptr->num, temp2.ptr->num);
	printf("%d / %d / %d\n", temp4.num, temp1.ptr->ptr->ptr->num, temp2.ptr->ptr->num);

	pointer = &temp1;
	printf("%d\n", pointer->num);
	pointer = &temp2;
	printf("%d\n", pointer->num);
	pointer = &temp3;
	printf("%d\n", pointer->num);
	pointer = &temp4;
	printf("%d\n", pointer->num);

	pointer = &temp1;
	printf("%d\n", pointer->num);
	pointer = pointer->ptr;
	printf("%d\n", pointer->num);
	pointer = pointer->ptr;
	printf("%d\n", pointer->num);
	pointer = pointer->ptr;
	printf("%d\n", pointer->num);

	/*test* test1;
	test* test2;
	test* test3;
	test* test4;

	test1 = malloc(sizeof(struct test));
	test2 = malloc(sizeof(struct test));
	test3 = malloc(sizeof(struct test));
	test4 = malloc(sizeof(struct test));

	test1->num = 100;
	strcpy(test1->str, "test1");
	test1->ptr = 0;
	
	test2->num = 200;
	strcpy(test2->str, "test2");
	test2->ptr = 0;

	test3->num = 300;
	strcpy(test3->str, "test3");
	test3->ptr = 0;

	test4->num = 400;
	strcpy(test4->str, "test4");
	test4->ptr = 0;

	test1->ptr = test2;
	test2->ptr = test3;
	test3->ptr = test4;

	printf("%d/%s/%p\n", test1->num, test1->str, test1->ptr);
	printf("%d/%d\n", test2->num,test2->ptr->num);

	*/

	test* temp1=0;
	test* original=0;

	temp1 = (test*)malloc(sizeof(test));
	temp1->num = 10;
	strcpy(temp1->str,"test1");
	temp1->ptr = 0;

	original = temp1;

	temp1->ptr = (test*)malloc(sizeof(test));
	temp1->ptr->num = 20;
	strcpy(temp1->ptr->str, "test2");
	temp1->ptr->ptr = 0;
	
	temp1 = temp1->ptr;

	temp1->ptr = (test*)malloc(sizeof(test));
	temp1->ptr->num = 30;
	temp1->ptr->ptr = 0;
	strcpy(temp1->ptr->str, "test3");

	temp1 = original;
	while (1) {
		if (temp1 == 0)break;
		printf("%d / %s / %p\n", temp1->num, temp1->str, temp1->ptr);

		temp1 = temp1->ptr;
	}

	return 0;
}