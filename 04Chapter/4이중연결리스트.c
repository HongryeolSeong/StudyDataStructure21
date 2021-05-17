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
		printf("메모리 할당 실패하였습니다.\n");
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
	if (preNode == NULL) // 헤드 바로 다음에 넣을 경우
	{
		if (phead->head == NULL) // 공백리스트인 경우
		{
			phead->head = newNode;
		}
		else if (phead->head != NULL) // 공백리스트가 아닌 경우
		{
			newNode->next = phead->head;
			newNode->next->prev = newNode;
			phead->head = newNode;
		}
	}
	else
	{
		// 노드 사이에 넣을 경우
		if (preNode->next != NULL)
		{
			newNode->next = preNode->next;
			newNode->next->prev = newNode;
		}
		// 마지막 노드 다음에 넣을 경우
		newNode->prev = preNode;
		preNode->next = newNode;
	}
}

void PrintNode(HeadNode* phead)
{
	int n = 1;
	if (phead->head == NULL)
	{
		printf("출력 결과 : 현재 헤드만 존재합니다.\n");
		printf("\n");
	}
	else
	{
		DListNode* curr = phead->head; // curr은 첫번째 노드로 시작
		while (curr != NULL)
		{
			printf("출력 결과 : %d번째 노드의 값은 : %d\n", n++, curr->data);
			curr = curr->next; // 마지막노드를 찾을때 까지 순회
		}
		printf("\n");
	}
}

void AllDelNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("삭제 실패 : 현재 헤드만 존재합니다.\n");
		printf("\n");
	}
	int n = 1;
	DListNode* temp;
	DListNode* curr = phead->head;
	while (curr != NULL)
	{
		temp = curr->next; // 다음 노드를 지우기 위해 해당 노드의 next를 temp에 저장
		printf("삭제 실행 : %d번째 노드를 삭제합니다.\n", n++);
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
	if (curr == NULL) printf("검색 실패 : 해당하는 data가 담긴 노드는 없습니다.\n");
	else printf("검색 결과 : %d을(를) 가진 노드는 %d번째 노드입니다.\n", data, n);
	printf("\n");
	return curr;
}

void DelNode(HeadNode* phead, DListNode* node) // 보수 필요
{
	int n = 2;

	if (node == NULL)
	{
		printf("삭제 실패 : 삭제할 노드가 없습니다.\n");
		printf("\n");
	}
	else if (phead->head == NULL)
	{
		printf("삭제 실패 : 현재 헤드만 존재합니다.\n");
		printf("\n");
	}
	else
	{
		if (phead->head == node) // 헤더 바로 다음 노드만 존재하는 경우
		{
			printf("삭제 실행 : 1번째 노드를 삭제합니다.\n");
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
			printf("삭제 실행 : %d번째 노드를 삭제합니다.\n", n);
			printf("\n");
			curr->next = node->next;
			curr->next->prev = curr;
			free(node);
		}
	}
}