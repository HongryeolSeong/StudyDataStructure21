#include <stdio.h>

typedef struct node
{
	int data;
	struct node* next;
} Node;

typedef struct
{
	Node* head; // Node를 가리킬 수 있는 멤버
} HeadNode; // 헤더

HeadNode* CreateHead();
Node* PreInsertNode(HeadNode* header, int data);
Node* RearInsertNode(HeadNode* header, int data);
void PrintNode(HeadNode* header);
void AllDeleteNode(HeadNode* header);
Node* SearchNode(HeadNode* header, int data);
void DeleteNode(HeadNode* header, Node* node);

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
	printf("\n");
	sn = SearchNode(h, 40);
	/*printf("\n");
	printf("해당 노드 : %u, %d\n", &sn, sn->data);*/
	printf("\n");
	DeleteNode(h, sn);
	printf("\n");
	PrintNode(h);

	return 0;
}

//헤더를 생성하는 함수
HeadNode* CreateHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL; // 역참조 방지. 역참조 : NULL이 h를 가리키는 경우

	return h;
}

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

Node* RearInsertNode(HeadNode* header, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode != NULL)
	{
		newnode->data = data;
		newnode->next = NULL;

		if (header->head == NULL) 
		{
			header->head = newnode;
		}
		else if (header->head != NULL) // h다음 노드가 있는 경우
		{
			Node* curr = header->head; // curr은 새 노드의 바로 전 노드
			while (curr->next != NULL) 
			{
				curr = curr->next; // n1에서 n2로 curr을 이동
			}
			curr->next = newnode; // while을 통해 curr을 정착시킨 후 새노드주소를 curr의 next에 대입
		}
	}
	return newnode;
}

void PrintNode(HeadNode* header)
{
	int n = 1;
	Node* curr = header->head; // curr은 첫번째 노드로 시작
	if (curr == NULL)
	{
		printf("현재 헤드만 존재합니다.\n");
	}
	else
	{
		while (curr != NULL)
		{
			printf("%d번째 노드의 값은 : %d\n", n++, curr->data);
			curr = curr->next; // 마지막노드를 찾을때 까지 순회
		}
	}
}

void AllDeleteNode(HeadNode* header)
{
	int n = 1;
	Node* temp;
	Node* curr = header->head;
	while (curr != NULL)
	{
		temp = curr->next; // 다음 노드를 지우기 위해 해당 노드의 next를 temp에 저장
		printf("%d번째 노드를 삭제합니다.\n", n++);
		free(curr);
		curr = temp;
	}
	header->head = NULL;
}

Node* SearchNode(HeadNode* header, int data)
{
	int n = 1;
	Node* curr = header->head;
	while (curr != NULL)
	{
		if (curr->data == data) break;
		curr = curr->next;
		n++;
	}
	if (curr == NULL) printf("해당하는 data가 담긴 노드는 없습니다.\n");
	else printf("%d번째 노드입니다.\n", n);
	
	return curr;
}

void DeleteNode(HeadNode* header, Node* node)
{
	if (node == NULL)
	{
		printf("삭제할 노드가 없습니다.\n");
	}
	else
	{
		if (header->head == node)
		{
			header->head = node->next;
			free(node);
		}
		else
		{
			Node* curr = header->head;
			while (curr != NULL)
			{
				if (curr->next == node) break;
				curr = curr->next;
			}
			curr->next = node->next;
			free(node);
		}
	}
}