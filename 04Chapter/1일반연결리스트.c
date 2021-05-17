#include <stdio.h>

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

	//if (node1 == NULL) // 동적 할당 실패시 = 포인터가 NULL 반환시
	//{
	//	printf("# 메모리가 부족합니다.\n");
	//	exit(1); // 프로그램 종료
	//}
	if (node1 == NULL) return;
	if (node2 == NULL) return;

	head->link = node1; // 헤더 노드에 첫번째 노드의 주소값을 넣는다.

	node1->data = 10;
	node1->link = node2;

	node2->data = 20;
	node2->link = node3;

	node3->data = 30;
	node3->link = node4;

	node4->data = 40;
	node4->link = node5;

	node5->data = 50;
	node5->link = NULL;

	Node* curr = head->link; // 첫번째 노드의 주소값
	while (curr != NULL)
	{
		printf("%d번째 노드의 값은 : %d\n", n++, curr->data);
		curr = curr->link;
	}

	free(node5);
	free(node4);
	free(node3);
	free(node2);
	free(node1);
	free(head);

	return 0;
}