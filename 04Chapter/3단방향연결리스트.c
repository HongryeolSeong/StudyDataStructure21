#include <stdio.h>
// 단방향 연결리스트 : 전위, 후위로 구성 가능하며 방향이 하나인 자료구조

typedef struct node // 일반 노드
{
	int data;
	struct node* next;
} Node;

typedef struct // 헤더
{
	Node* head; // Node를 가리킬 수 있는 멤버
} HeadNode;

HeadNode* CreateHead(); // 헤더 생성
Node* PreInsertNode(HeadNode* header, int data); // 전위 추가
void MidInsertNode(HeadNode* header, Node* pn, int data); // 중위 추가
Node* RearInsertNode(HeadNode* header, int data); // 후위 추가
void PrintNode(HeadNode* header); // 연결리스트 출력
void AllDeleteNode(HeadNode* header); // 전체 노드 삭제
Node* SearchNode(HeadNode* header, int data); // 데이터를 통한 노드 검색
void DeleteNode(HeadNode* header, Node* node); // 한 개 노드 삭제

int main()
{
	int n = 1;
	HeadNode* h;
	Node* n1;
	Node* n2;
	Node* n3;
	Node* n4;
	Node* n5;
	Node* sn;

	h = CreateHead();
	n1 = RearInsertNode(h, 10);
	n2 = RearInsertNode(h, 20);
	n3 = RearInsertNode(h, 30);
	n4 = PreInsertNode(h, 40);
	n5 = PreInsertNode(h, 50);

	PrintNode(h);
	/*sn = SearchNode(h, 30);
	DeleteNode(h, n3);
	MidInsertNode(h, n1, 7);
	sn = SearchNode(h, 7);
	PrintNode(h);*/

	return 0;
}

// 헤더 생성
HeadNode* CreateHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL; // 역참조 방지. 역참조 : NULL이 h를 가리키는 경우

	return h;
}

// 전위 노드 추가
Node* PreInsertNode(HeadNode* header, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode != NULL)
	{
		newnode->data = data;
		newnode->next = header->head;
		header->head = newnode;
	}

	return newnode;
}

// 중위 노드 추가
void MidInsertNode(HeadNode* header, Node* pn, int data)
{
	int n = 1;

	// 삽입할 노드 위치의 전노드 찾기
	Node* curr = header->head; // curr은 n1부터 시작
	while (curr != NULL)
	{
		if (curr == pn) break; // 입력 변수인 pn를 찾을시 curr은 스탑 curr = pn
		curr = curr->next;
		n++;
	}
	// 위 반복문이 끝난 후 curr = 삽입할 노드 위치 바로 전 노드

	// curr 다음에 새 노드 삽입하기
	Node* newnode = (Node*)malloc(sizeof(Node)); // 새노드 생성
	if (newnode != NULL)
	{
		// 헤더 바로 다음 삽입하는 경우
		if (curr == header)
		{
			newnode->data = data;
			newnode->next = NULL;
			header->head = newnode;
			printf("헤더 바로 다음에 노드를 삽입하였습니다.");
			printf("\n");
		}
		// 입력 변수인 노드가 NULL인 경우
		else if (pn == NULL)
		{
			printf("삽입할 위치를 찾을 수 없습니다.");
			printf("\n");
		}
		// pn이 일반적인 노드인 경우
		else
		{
			newnode->data = data;
			// 새노드 next에 그 전노드의 next를 넣어 새노드와 새노드의 다음 노드와 연결
			newnode->next = curr->next;
			curr->next = newnode; // 전노드와 새노드 연결
			printf("%d번째 노드와 %d번째 노드 사이에 새 노드 삽입 완료\n", n, n + 1);
			printf("\n");
		}
	}
}

// 후위 노드 추가
Node* RearInsertNode(HeadNode* header, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode != NULL)
	{
		// data와 next는 일단 초기화 함
		newnode->data = data;
		newnode->next = NULL;

		// 새 노드와 전 노드의 연결 처리
		// 헤더 바로 다음에 추가하는 경우
		if (header->head == NULL)
		{
			header->head = newnode;
		}
		// 헤더 바로 다음 노드가 존재하는 경우
		else if (header->head != NULL)
		{
			Node* curr = header->head;
			while (curr->next != NULL) // curr은 현 마지막 노드
			{
				curr = curr->next; // 처음부터 순회하여 마지막 노드에 도달
			}
			curr->next = newnode; // 새노드주소를 curr의 next에 대입
		}
	}
	return newnode;
}

// 전체 출력
void PrintNode(HeadNode* header)
{
	int n = 1;
	Node* curr = header->head; // curr은 첫번째 노드로 시작

	// 현재 헤더만 있는 경우
	if (curr == NULL)
	{
		printf("출력 결과 : 현재 헤더만 존재합니다.\n");
		printf("\n");
	}
	// 헤더 이후 노드가 있는 경우
	else
	{
		while (curr != NULL)
		{
			printf("출력 결과 : %d번째 노드의 값은 : %d\n", n++, curr->data);
			curr = curr->next; // 마지막노드를 찾을때 까지 순회
		}
		printf("\n");
	}
}

// 연결리스트의 전체 노드 삭제
void AllDeleteNode(HeadNode* header)
{
	// 현재 헤더만 있는 경우
	if (header->head == NULL)
	{
		printf("삭제 실패 : 현재 헤더만 존재합니다.\n");
		printf("\n");
	}

	// 헤더 이후 노드가 존재하는 경우
	int n = 1;
	Node* temp;
	Node* curr = header->head;
	while (curr != NULL)
	{
		temp = curr->next; // 다음 노드를 지우기 위해 해당 노드의 next를 temp에 저장
		printf("삭제 실행 : %d번째 노드를 삭제합니다.\n", n++);
		free(curr); // curr 내 동적 할당된 노드 삭제(curr은 그대로 유지)
		curr = temp; // 해제된 노드의 다음 노드를 가리키는 curr
	}
	header->head = NULL; // 모두 해제 한 후 헤더의 연결 처리
	printf("\n");
}

// 데이터를 통한 노드 검색
Node* SearchNode(HeadNode* header, int data)
{
	int n = 1;
	Node* curr = header->head;
	while (curr != NULL)
	{
		if (curr->data == data) break; // 해당 data를 가진 노드를 가리키게 되면 탈출
		curr = curr->next;
		n++;
	}
	if (curr == NULL) printf("검색 실패 : 해당하는 data가 담긴 노드는 없습니다.\n");
	else printf("검색 결과 : %d을(를) 가진 노드는 %d번째 노드입니다.\n", data, n);
	printf("\n");
	return curr;
}

// 한 노드 삭제
void DeleteNode(HeadNode* header, Node* node)
{
	int n = 2;

	// 해당 노드가 존재하지 않는 경우
	if (node == NULL)
	{
		printf("삭제 실패 : 삭제할 노드가 없습니다.\n");
		printf("\n");
	}
	// 현재 헤더만 존재하는 경우
	else if (header->head == NULL)
	{
		printf("삭제 실패 : 현재 헤더만 존재합니다.\n");
		printf("\n");
	}
	else
	{
		// 헤더 바로 다음 노드를 삭제하는 경우
		if (header->head == node)
		{
			printf("삭제 실행 : 1번째 노드를 삭제합니다.\n");
			printf("\n");
			header->head = node->next; // 헤더와 삭제 노드의 다음 노드를 연결 
			free(node);
		}
		// 두번째 노드 및 그 이후 노드를 삭제하는 경우
		else
		{
			Node* curr = header->head;
			while (curr != NULL)
			{
				if (curr->next == node) break; // 삭제할 노드의 전 노드를 탐색
				curr = curr->next;
				n++;
			}
			printf("삭제 실행 : %d번째 노드를 삭제합니다.\n", n);
			printf("\n");
			curr->next = node->next; // 전 노드와 다음 노드를 연결
			free(node); // 원래 목표였던 노드 삭제
		}
	}
}

