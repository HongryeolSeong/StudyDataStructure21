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
		printf("메모리 할당 실패!");
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
	if (h->head == NULL) // 공백리스트인 경우
	{
		h->head = newNode;
		newNode->link = newNode; // 자기자신을 가리킴(원형이어서)
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
		printf("출력 결과 : 현재 헤드만 존재합니다.\n");
		printf("\n");
	}
	else
	{
		ListNode* curr = h->head; // curr은 헤드가 가리키는 노드로 시작
		do
		{
			printf("출력 결과 : %d번째 노드의 값은 : %d\n", n++, curr->data);
			curr = curr->link; // 마지막노드를 찾을때 까지 순회
			printf("\n");
		} while (curr != h->head);
	}
}

void AllDelNode(HeadNode* h)
{
	if (h->head == NULL)
	{
		printf("삭제 실패 : 현재 헤드만 존재합니다.\n");
		printf("\n");
	}
	int n = 1;
	ListNode* temp;
	ListNode* curr = h->head;
	do
	{
		temp = curr->link; // 다음 노드를 지우기 위해 해당 노드의 next를 temp에 저장
		printf("삭제 실행 : %d번째 노드를 삭제합니다.\n", n++);
		free(curr);
		curr = temp;
	} while (curr != h->head);
	h->head = NULL;
	printf("\n");
}