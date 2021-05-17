#include <stdio.h>

typedef struct listnode
{
	int data;
	struct listnode* link;
} ListNode;

typedef struct
{
	ListNode* head;
} HeadNode;

HeadNode* CreateHead();
ListNode* CreateNode(HeadNode* h, int data);
void InsertFirstNode(HeadNode* h, ListNode* newNode);
void InsertLastNode(HeadNode* h, ListNode* newNode);
void PrintNode(HeadNode* h);
void AllDelNode(HeadNode* h);

int main()
{
	HeadNode* h = CreateHead();
	ListNode* n1 = CreateNode(h, 10);
	ListNode* n2 = CreateNode(h, 20);
	ListNode* n3 = CreateNode(h, 30);
	ListNode* n4 = CreateNode(h, 40);
	ListNode* n5 = CreateNode(h, 50);

	InsertLastNode(h, n1);
	InsertLastNode(h, n2);
	InsertLastNode(h, n3);
	InsertLastNode(h, n4);
	InsertFirstNode(h, n5);
	PrintNode(h);
	AllDelNode(h);
	PrintNode(h);

	return 0;
}

HeadNode* CreateHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}

ListNode* CreateNode(HeadNode* h, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("�޸� �Ҵ� ����!");
		return;
	}
	else
	{
		newNode->data = data;
		newNode->link = NULL;
		return newNode;
	}
}

void InsertLastNode(HeadNode* h, ListNode* newNode)
{
	if (h->head == NULL) // ���鸮��Ʈ�� ���
	{
		h->head = newNode;
		newNode->link = newNode; // �ڱ��ڽ��� ����Ŵ(�����̾)
	}
	else
	{
		newNode->link = h->head->link;
		h->head->link = newNode;
		h->head = newNode;
	}
}

void InsertFirstNode(HeadNode* h, ListNode* newNode)
{
	if (h->head == NULL)
	{
		h->head = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = h->head->link;
		h->head->link = newNode;
	}
}

void PrintNode(HeadNode* h)
{
	int n = 1;
	if (h->head == NULL)
	{
		printf("��� ��� : ���� ��常 �����մϴ�.\n");
		printf("\n");
	}
	else
	{
		ListNode* curr = h->head; // curr�� ��尡 ����Ű�� ���� ����
		do
		{
			printf("��� ��� : %d��° ����� ���� : %d\n", n++, curr->data);
			curr = curr->link; // ��������带 ã���� ���� ��ȸ
			printf("\n");
		} while (curr != h->head);
	}
}

void AllDelNode(HeadNode* h)
{
	if (h->head == NULL)
	{
		printf("���� ���� : ���� ��常 �����մϴ�.\n");
		printf("\n");
	}
	int n = 1;
	ListNode* temp;
	ListNode* curr = h->head;
	do
	{
		temp = curr->link; // ���� ��带 ����� ���� �ش� ����� next�� temp�� ����
		printf("���� ���� : %d��° ��带 �����մϴ�.\n", n++);
		free(curr);
		curr = temp;
	} while (curr != h->head);
	h->head = NULL;
	printf("\n");
}