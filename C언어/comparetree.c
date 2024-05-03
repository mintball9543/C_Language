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
		printf("[�޴�]\n");
		printf("1.����߰� 2.������(����) 3.������(����) 4.������(����) 5.����\n");
		printf("�޴�����: ");
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
		//�θ𰪰� ��, �۰�, ���ʿ� �ڽ��� ���� ���
		   //�����ڽ����� �̵��� �ٽ� ��
		   //������ ������ ����
		//�׷��� �ʰ�, ������ �ڽ��� ������
		   //���������� �̵��� �ٽú�
		   //������ ������ ����

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

	printf("���ڸ� �Է��ϼ���: ");
	scanf("%d", &temp.num);

	return temp;
}

void printtree(tree* root, int mode) {
	if (mode == 1) { //����
		printf("%d\n", root->node.num);

		if (root->left != NULL) {
			printtree(root->left, 1);
		}
		if (root->right != NULL) {
			printtree(root->right, 1);
		}
	}
	else if (mode == 2) { //����
		if (root->left != NULL) {
			printtree(root->left, 2);
		}

		printf("%d\n", root->node.num);

		if (root->right != NULL) {
			printtree(root->right, 2);
		}
	}
	else { //����
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