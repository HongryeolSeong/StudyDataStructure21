#include <stdio.h>
// 전위 연결리스트 : 추가된 노드의 위치는 헤더 바로 다음.

typedef struct node
{
	int data;
	struct node* link;
} Node;

void addNode(Node* target, int data);

int main()
{
	int n = 1;

	Node* head = (Node*)malloc(sizeof(Node));

	head->link = NULL;
	addNode(head, 10);
	addNode(head, 20);
	addNode(head, 30);
	addNode(head, 40);
	addNode(head, 50);

	// 연결리스트 출력을 위한 순회 노드 curr
	Node* curr = head->link;
	while (curr != NULL)
	{
		printf("%d번째 노드의 값은 : %d\n", n++, curr->data);
		curr = curr->link;
	}

	// 동적 할당 해제를 위한 순회 노드 temp
	Node* temp;
	// curr은 첫 노드부터 마지막 다음 노드까지 반복
	for (curr = head->link; curr != NULL; curr->link)
	{
		temp = curr->link; // 해당 노드의 link를 temp에 저장
		free(curr); // 해당 노드 할당 해제
		curr = temp; // 해제 다음 노드를 가리키는 curr
	}

	// 동적 할당 해제 확인을 위한 출력문
	n = 1;
	Node* curr2 = head->link;
	while (curr2 != NULL)
	{
		if (curr2 != NULL)
		{
			printf("현재 헤더만 존재합니다.");
			break;
		}
		printf("%d번째 노드의 값은 : %d\n", n++, curr2->data);
		curr2 = curr2->link;
	}

	return 0;
}

// 전위 방식으로 노드를 추가하는 함수
void addNode(Node* target, int data)
{
	Node* newNode = malloc(sizeof(Node)); // 새 노드 생성
	newNode->data = data; // 노드에 data 대입
	newNode->link = target->link; // head의 link값을 newNode의 link에 대입
	target->link = newNode; // head의 link값은 newNode의 주소가 됨
}