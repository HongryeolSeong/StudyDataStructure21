#include <stdio.h>
// 이중(양방향) 연결리스트 : 단방향과 달리 노드가 서로를 가리킴

typedef struct dlistnode
{
	int data;
	struct dlistnode* next; // 다음 노드를 가리킴
	struct dlistnode* prev; // 이전 노드를 가리킴
} DListNode;

typedef struct
{
	DListNode* head;
} HeadNode;

HeadNode* CreateHead(); // 헤더 생성
DListNode* CreateNode(int data); // 노드 생성
void InsertNode(HeadNode* phead, DListNode* preNode, DListNode* newNode); // 노드 삽입
void PrintNode(HeadNode* header); // 전체 출력
void AllDelNode(HeadNode* phead); // 전체 삭제
DListNode* FindNode(HeadNode* phead, int data); // 노드 검색
void DelNode(HeadNode* phead, DListNode* node); // 한 노드 삭제

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
	DelNode(h, n3);
	PrintNode(h);

	return 0;
}

// 헤더 생성
HeadNode* CreateHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}

// 노드 생성
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
		// 생성시 데이터값만 가지게 됨
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
}

// 노드를 삽입
void InsertNode(HeadNode* phead, DListNode* preNode, DListNode* newNode)
{
	// 헤드 바로 다음에 넣을 경우
	if (preNode == NULL)
	{
		// 공백리스트인 경우
		if (phead->head == NULL)
		{
			phead->head = newNode;
		}
		// 공백리스트가 아닌 경우
		else if (phead->head != NULL)
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

// 전체 출력
void PrintNode(HeadNode* phead)
{
	int n = 1;

	// 공백리스트인 경우
	if (phead->head == NULL)
	{
		printf("출력 결과 : 현재 헤드만 존재합니다.\n");
		printf("\n");
	}
	// 출력할 노드가 있는 경우
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

// 전체 삭제
void AllDelNode(HeadNode* phead)
{
	// 공백리스트인 경우
	if (phead->head == NULL)
	{
		printf("삭제 실패 : 현재 헤드만 존재합니다.\n");
		printf("\n");
	}

	// 삭제할 노드가 있는 경우
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

// 노드 검색
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

// 한 노드 삭제
void DelNode(HeadNode* phead, DListNode* node) // 보수 필요
{
	int n = 2;

	// 해당 노드가 없는 경우
	if (node == NULL)
	{
		printf("삭제 실패 : 삭제할 노드가 없습니다.\n");
		printf("\n");
	}
	// 공백리스트인 경우
	else if (phead->head == NULL)
	{
		printf("삭제 실패 : 현재 헤드만 존재합니다.\n");
		printf("\n");
	}
	else
	{
		// 첫 노드만 존재하는 경우
		if (phead->head == node)
		{
			printf("삭제 실행 : 1번째 노드를 삭제합니다.\n");
			printf("\n");
			phead->head = node->next;
			free(node);
		}
		// 노드가 두 개 이상인 경우
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

			// 삭제할 노드가 마지막인 경우
			if (curr->next->next == NULL)
			{
				curr->next = NULL;
				free(node);
			}
			// 삭제할 노드가 마지막이 아닌 경우
			else
			{
				curr->next = node->next;
				curr->next->prev = curr;
				free(node);
			}
		}
	}
}