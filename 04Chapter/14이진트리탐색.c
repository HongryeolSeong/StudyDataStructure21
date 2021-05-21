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
	printf("\n 찾는 키가 없습니다!");
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
	else printf("\n 이미 같은 키가 있습니다!! \n"); 

	return p;
}

void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;

	//삭제할 노드의 위치 탐색
	while ((p != NULL) && (p->key != key))
	{
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	//삭제할 노드가 없는 경우
	if (p == NULL)
	{
		printf("\n 찾는 키가 이전 트리에 없습니다!!");
		return;
	}

	//삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL))
	{
		if (parent != NULL)
		{
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	//삭제할 노드가 자식 노드를 한 개 가진 경우
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

	//삭제할 노드가 자식 노드를 두 개 가진 경우
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