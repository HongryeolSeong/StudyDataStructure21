#include <stdio.h>
// 일반 연결리스트

typedef struct node
{
	int data; // data 멤버
	struct node* link; // 다음 노드 주소를 저장할 멤버
}Node;

int main()
{
	int n = 1;
	int i;
	Node* head = (Node*)malloc(sizeof(Node));
	Node* node1 = (Node*)malloc(sizeof(Node)); // 노드 생성
	Node* node2 = (Node*)malloc(sizeof(Node)); // 노드 생성
	Node* node3 = (Node*)malloc(sizeof(Node));
	Node* node4 = (Node*)malloc(sizeof(Node));
	Node* node5 = (Node*)malloc(sizeof(Node));

	// 추가시 더 안전성 있음
	//if (node1 == NULL) // 동적 할당 실패시 = 포인터가 NULL 반환시
	//{
	//	printf("# 메모리가 부족합니다.\n");
	//	exit(1); // 프로그램 종료
	//}

	// 추가시 더 안전성 있음
	if (node1 == NULL) return;
	if (node2 == NULL) return;
	if (node3 == NULL) return;
	if (node4 == NULL) return;
	if (node5 == NULL) return;

	head->link = node1; // 헤더 노드에 첫번째 노드의 주소값을 넣는다.

	node1->data = 10;
	node1->link = node2; // 노드 2를 가리킴

	node2->data = 20;
	node2->link = node3; // 노드 3를 가리킴

	node3->data = 30;
	node3->link = node4; // 노드 4를 가리킴

	node4->data = 40;
	node4->link = node5; // 노드 5를 가리킴

	node5->data = 50;
	node5->link = NULL; // 마지막 노드라 가리키는게 없다


	Node* curr = head->link; // 연결리스트를 순회 할 노드 curr
	while (curr != NULL)
	{
		printf("%d번째 노드의 값은 : %d\n", n++, curr->data);
		curr = curr->link;
	}

	// 동적 할당 해제
	free(node5);
	free(node4);
	free(node3);
	free(node2);
	free(node1);
	free(head);

	return 0;
}