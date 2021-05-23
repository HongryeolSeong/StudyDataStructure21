#include <stdio.h>
// ���� ���Ḯ��Ʈ : �߰��� ����� ��ġ�� ��� �ٷ� ����.

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

	// ���Ḯ��Ʈ ����� ���� ��ȸ ��� curr
	Node* curr = head->link;
	while (curr != NULL)
	{
		printf("%d��° ����� ���� : %d\n", n++, curr->data);
		curr = curr->link;
	}

	// ���� �Ҵ� ������ ���� ��ȸ ��� temp
	Node* temp;
	// curr�� ù ������ ������ ���� ������ �ݺ�
	for (curr = head->link; curr != NULL; curr->link)
	{
		temp = curr->link; // �ش� ����� link�� temp�� ����
		free(curr); // �ش� ��� �Ҵ� ����
		curr = temp; // ���� ���� ��带 ����Ű�� curr
	}

	// ���� �Ҵ� ���� Ȯ���� ���� ��¹�
	n = 1;
	Node* curr2 = head->link;
	while (curr2 != NULL)
	{
		if (curr2 != NULL)
		{
			printf("���� ����� �����մϴ�.");
			break;
		}
		printf("%d��° ����� ���� : %d\n", n++, curr2->data);
		curr2 = curr2->link;
	}

	return 0;
}

// ���� ������� ��带 �߰��ϴ� �Լ�
void addNode(Node* target, int data)
{
	Node* newNode = malloc(sizeof(Node)); // �� ��� ����
	newNode->data = data; // ��忡 data ����
	newNode->link = target->link; // head�� link���� newNode�� link�� ����
	target->link = newNode; // head�� link���� newNode�� �ּҰ� ��
}