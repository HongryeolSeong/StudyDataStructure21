#include <stdio.h>
// �Ϲ� ���Ḯ��Ʈ

typedef struct node
{
	int data; // data ���
	struct node* link; // ���� ��� �ּҸ� ������ ���
}Node;

int main()
{
	int n = 1;
	int i;
	Node* head = (Node*)malloc(sizeof(Node));
	Node* node1 = (Node*)malloc(sizeof(Node)); // ��� ����
	Node* node2 = (Node*)malloc(sizeof(Node)); // ��� ����
	Node* node3 = (Node*)malloc(sizeof(Node));
	Node* node4 = (Node*)malloc(sizeof(Node));
	Node* node5 = (Node*)malloc(sizeof(Node));

	// �߰��� �� ������ ����
	//if (node1 == NULL) // ���� �Ҵ� ���н� = �����Ͱ� NULL ��ȯ��
	//{
	//	printf("# �޸𸮰� �����մϴ�.\n");
	//	exit(1); // ���α׷� ����
	//}

	// �߰��� �� ������ ����
	if (node1 == NULL) return;
	if (node2 == NULL) return;
	if (node3 == NULL) return;
	if (node4 == NULL) return;
	if (node5 == NULL) return;

	head->link = node1; // ��� ��忡 ù��° ����� �ּҰ��� �ִ´�.

	node1->data = 10;
	node1->link = node2; // ��� 2�� ����Ŵ

	node2->data = 20;
	node2->link = node3; // ��� 3�� ����Ŵ

	node3->data = 30;
	node3->link = node4; // ��� 4�� ����Ŵ

	node4->data = 40;
	node4->link = node5; // ��� 5�� ����Ŵ

	node5->data = 50;
	node5->link = NULL; // ������ ���� ����Ű�°� ����


	Node* curr = head->link; // ���Ḯ��Ʈ�� ��ȸ �� ��� curr
	while (curr != NULL)
	{
		printf("%d��° ����� ���� : %d\n", n++, curr->data);
		curr = curr->link;
	}

	// ���� �Ҵ� ����
	free(node5);
	free(node4);
	free(node3);
	free(node2);
	free(node1);
	free(head);

	return 0;
}