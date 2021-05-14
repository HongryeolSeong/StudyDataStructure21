#include <stdio.h>

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


	Node* curr = head->link; // 첫번째 노드의 주소값
	while (curr != NULL)
	{
		printf("%d번째 노드의 값은 : %d\n", n++, curr->data);
		curr = curr->link;
	}

	Node* temp;
	for (curr; curr != NULL; curr->link)
	{
		temp = curr->link;
		free(curr);
		curr = temp;
	}

	return 0;
}

void addNode(Node* target, int data)
{
	Node* newNode = malloc(sizeof(Node)); // 새 노드 생성
	newNode->data = data;
	newNode->link = target->link; // head의 link값을 newNode의 link에 대입
	target->link = newNode; // head의 link값은 newNode의 주소가 됨
}