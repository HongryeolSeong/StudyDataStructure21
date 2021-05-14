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


	Node* curr = head->link; // ù��° ����� �ּҰ�
	while (curr != NULL)
	{
		printf("%d��° ����� ���� : %d\n", n++, curr->data);
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
	Node* newNode = malloc(sizeof(Node)); // �� ��� ����
	newNode->data = data;
	newNode->link = target->link; // head�� link���� newNode�� link�� ����
	target->link = newNode; // head�� link���� newNode�� �ּҰ� ��
}