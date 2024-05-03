#include<stdio.h>
#include<stdlib.h>

struct data {
	int num;
};

struct tree {
	struct data node;
	struct tree* left;
	struct tree* right;
};

typedef struct data data;
typedef struct tree tree;

tree* createnode();
tree* addtree(tree* parent);
data inputdata();
void printtree(tree* root, int mode);

int main() {
	//tree* arr[512] = { 0 };
	tree* root = 0;
	int menu = 0;
	int count = 0;
	int index = 0;
	int child_i = 0;
	int i = 0;

	while (1)
	{
		printf("[메뉴]\n");
		printf("1.노드추가 2.노드출력(전위) 3.노드출력(중위) 4.노드출력(후위) 5.종료\n");
		printf("메뉴선택: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			if (root == NULL)
				root = addtree(root);
			else
				addtree(root);
			break;
		case 2:
			printtree(root, 1);
			break;
		case 3:
			printtree(root, 2);
			break;
		case 4:
			printtree(root, 3);
			break;
		case 5:
			break;
		}

		if (menu == 5) break;
	}

	return 0;
}

tree* createnode() {
	tree* temp;
	int i = 0;

	temp = malloc(sizeof(tree));

	temp->left = temp->right = NULL;
	temp->node.num = NULL;

	return temp;
}

tree* addtree(tree* parent) {
	tree* temp;
	temp = createnode();
	temp->node = inputdata();


	if (parent == NULL) {
		parent = temp;
		return temp;
	}


	while (1) {
		//부모값과 비교, 작고, 왼쪽에 자식이 있을 경우
		   //왼쪽자식으로 이동후 다시 비교
		   //없으면 포인터 지정
		//그렇지 않고, 오른쪽 자식이 있으면
		   //오른쪽으로 이동후 다시비교
		   //없으면 포인터 지정

		if (parent->node.num >= temp->node.num && parent->left != NULL) {
			parent = parent->left;
			continue;
		}
		else if (parent->node.num >= temp->node.num && parent->left == NULL) {
			parent->left = temp;
			return temp;
		}

		if (parent->node.num < temp->node.num && parent->right != NULL) {
			parent = parent->right;
			continue;
		}
		else if (parent->node.num < temp->node.num && parent->right == NULL) {
			parent->right = temp;
			return temp;
		}
	}

	return temp;
}

data inputdata() {
	data temp;

	printf("숫자를 입력하세요: ");
	scanf("%d", &temp.num);

	return temp;
}

void printtree(tree* root, int mode) {
	if (mode == 1) { //전위
		printf("%d\n", root->node.num);

		if (root->left != NULL) {
			printtree(root->left, 1);
		}
		if (root->right != NULL) {
			printtree(root->right, 1);
		}
	}
	else if (mode == 2) { //중위
		if (root->left != NULL) {
			printtree(root->left, 2);
		}

		printf("%d\n", root->node.num);

		if (root->right != NULL) {
			printtree(root->right, 2);
		}
	}
	else { //후위
		if (root->left != NULL) {
			printtree(root->left, 3);
		}

		if (root->right != NULL) {
			printtree(root->right, 3);
		}

		printf("%d\n", root->node.num);

		return;
	}
}