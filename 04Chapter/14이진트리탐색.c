#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treeNode
{
	char key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* searchBST(treeNode* root, char x);
treeNode* insertNode(treeNode* p, char x);
void deleteNode(treeNode* root, element key);
void displayInorder(treeNode* root);

int main()
{
	treeNode* root = NULL;
	//searchBST(root, 'k');
	root = insertNode(root, 'k');
	insertNode(root, 'i');
	insertNode(root, 'c');
	insertNode(root, 'j');
	//insertNode(root, 'j');
	insertNode(root, 'b');
	insertNode(root, 'z');
	insertNode(root, 'o');
	deleteNode(root, 'i');
	displayInorder(root);

	return 0;
}

treeNode* searchBST(treeNode* root, char x)
{
	treeNode* p;
	p = root;
	while (p != NULL)
	{
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\n ã�� Ű�� �����ϴ�!");
	return p;
}

treeNode* insertNode(treeNode* p, char x)
{
	treeNode* newNode;
	if (p == NULL)
	{
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertNode(p->left, x);
	else if (x > p->key) p->right = insertNode(p->right, x);
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�!! \n"); 

	return p;
}

void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;

	//������ ����� ��ġ Ž��
	while ((p != NULL) && (p->key != key))
	{
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	//������ ��尡 ���� ���
	if (p == NULL)
	{
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");
		return;
	}

	//������ ��尡 �ܸ� ����� ���
	if ((p->left == NULL) && (p->right == NULL))
	{
		if (parent != NULL)
		{
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	//������ ��尡 �ڽ� ��带 �� �� ���� ���
	else if ((p->left == NULL) || (p->right == NULL))
	{
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL)
		{
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	//������ ��尡 �ڽ� ��带 �� �� ���� ���
	else
	{
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

void displayInorder(treeNode* root)
{
	if (root)
	{
		displayInorder(root->left);
		printf("_%c", root->key);
		displayInorder(root->right);
	}
}