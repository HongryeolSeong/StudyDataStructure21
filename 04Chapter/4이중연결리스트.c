#include <stdio.h>

typedef struct dlistnode
{
	int data;
	struct dlistnode* next;
	struct dlistnode* prev;
} DListNode;

typedef struct
{
	DListNode* head;
} HeadNode;

HeadNode* CreateHead();
DListNode* CreateNode(int data);
void InsertNode(HeadNode* phead, DListNode* preNode, DListNode* newNode);
void PrintNode(HeadNode* header);
void AllDelNode(HeadNode* phead);
DListNode* FindNode(HeadNode* phead, int data);
void DelNode(HeadNode* phead, DListNode* node);

int main()
{
	HeadNode* h = CreateHead();
	DListNode* n1 = CreateNode(10);
	DListNode* n2 = CreateNode(20);
	DListNode* n3 = CreateNode(30);
	DListNode* n4 = CreateNode(40);
	DListNode* n5 = CreateNode(7);
	DListNode* sn;

	InsertNode(h, NULL, n1);
	InsertNode(h, n1, n2);
	InsertNode(h, n2, n3);
	InsertNode(h, n1, n4);
	InsertNode(h, NULL, n5);

	PrintNode(h);
	sn = FindNode(h, 30);
	//AllDelNode(h);
	DelNode(h, sn);
	PrintNode(h);

	return 0;
}

HeadNode* CreateHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}

DListNode* CreateNode(int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		printf("�޸� �Ҵ� �����Ͽ����ϴ�.\n");
		exit(1);
	}
	else
	{
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
}

void InsertNode(HeadNode* phead, DListNode* preNode, DListNode* newNode)
{
	if (preNode == NULL) // ��� �ٷ� ������ ���� ���
	{
		if (phead->head == NULL) // ���鸮��Ʈ�� ���
		{
			phead->head = newNode;
		}
		else if (phead->head != NULL) // ���鸮��Ʈ�� �ƴ� ���
		{
			newNode->next = phead->head;
			newNode->next->prev = newNode;
			phead->head = newNode;
		}
	}
	else
	{
		// ��� ���̿� ���� ���
		if (preNode->next != NULL)
		{
			newNode->next = preNode->next;
			newNode->next->prev = newNode;
		}
		// ������ ��� ������ ���� ���
		newNode->prev = preNode;
		preNode->next = newNode;
	}
}

void PrintNode(HeadNode* phead)
{
	int n = 1;
	if (phead->head == NULL)
	{
		printf("��� ��� : ���� ��常 �����մϴ�.\n");
		printf("\n");
	}
	else
	{
		DListNode* curr = phead->head; // curr�� ù��° ���� ����
		while (curr != NULL)
		{
			printf("��� ��� : %d��° ����� ���� : %d\n", n++, curr->data);
			curr = curr->next; // ��������带 ã���� ���� ��ȸ
		}
		printf("\n");
	}
}

void AllDelNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("���� ���� : ���� ��常 �����մϴ�.\n");
		printf("\n");
	}
	int n = 1;
	DListNode* temp;
	DListNode* curr = phead->head;
	while (curr != NULL)
	{
		temp = curr->next; // ���� ��带 ����� ���� �ش� ����� next�� temp�� ����
		printf("���� ���� : %d��° ��带 �����մϴ�.\n", n++);
		free(curr);
		curr = temp;
	}
	phead->head = NULL;
	printf("\n");
}

DListNode* FindNode(HeadNode* phead, int data)
{
	int n = 1;
	DListNode* curr = phead->head;
	while (curr != NULL)
	{
		if (curr->data == data) break;
		curr = curr->next;
		n++;
	}
	if (curr == NULL) printf("�˻� ���� : �ش��ϴ� data�� ��� ���� �����ϴ�.\n");
	else printf("�˻� ��� : %d��(��) ���� ���� %d��° ����Դϴ�.\n", data, n);
	printf("\n");
	return curr;
}

void DelNode(HeadNode* phead, DListNode* node) // ���� �ʿ�
{
	int n = 2;

	if (node == NULL)
	{
		printf("���� ���� : ������ ��尡 �����ϴ�.\n");
		printf("\n");
	}
	else if (phead->head == NULL)
	{
		printf("���� ���� : ���� ��常 �����մϴ�.\n");
		printf("\n");
	}
	else
	{
		if (phead->head == node) // ��� �ٷ� ���� ��常 �����ϴ� ���
		{
			printf("���� ���� : 1��° ��带 �����մϴ�.\n");
			printf("\n");
			phead->head = node->next;
			free(node);
		}
		else
		{
			DListNode* curr = phead->head;
			while (curr != NULL)
			{
				if (curr->next == node) break;
				curr = curr->next;
				n++;
			}
			printf("���� ���� : %d��° ��带 �����մϴ�.\n", n);
			printf("\n");
			curr->next = node->next;
			curr->next->prev = curr;
			free(node);
		}
	}
}