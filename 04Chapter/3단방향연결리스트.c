#include <stdio.h>
// �ܹ��� ���Ḯ��Ʈ : ����, ������ ���� �����ϸ� ������ �ϳ��� �ڷᱸ��

typedef struct node // �Ϲ� ���
{
	int data;
	struct node* next;
} Node;

typedef struct // ���
{
	Node* head; // Node�� ����ų �� �ִ� ���
} HeadNode;

HeadNode* CreateHead(); // ��� ����
Node* PreInsertNode(HeadNode* header, int data); // ���� �߰�
void MidInsertNode(HeadNode* header, Node* pn, int data); // ���� �߰�
Node* RearInsertNode(HeadNode* header, int data); // ���� �߰�
void PrintNode(HeadNode* header); // ���Ḯ��Ʈ ���
void AllDeleteNode(HeadNode* header); // ��ü ��� ����
Node* SearchNode(HeadNode* header, int data); // �����͸� ���� ��� �˻�
void DeleteNode(HeadNode* header, Node* node); // �� �� ��� ����

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

// ��� ����
HeadNode* CreateHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL; // ������ ����. ������ : NULL�� h�� ����Ű�� ���

	return h;
}

// ���� ��� �߰�
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

// ���� ��� �߰�
void MidInsertNode(HeadNode* header, Node* pn, int data)
{
	int n = 1;

	// ������ ��� ��ġ�� ����� ã��
	Node* curr = header->head; // curr�� n1���� ����
	while (curr != NULL)
	{
		if (curr == pn) break; // �Է� ������ pn�� ã���� curr�� ��ž curr = pn
		curr = curr->next;
		n++;
	}
	// �� �ݺ����� ���� �� curr = ������ ��� ��ġ �ٷ� �� ���

	// curr ������ �� ��� �����ϱ�
	Node* newnode = (Node*)malloc(sizeof(Node)); // ����� ����
	if (newnode != NULL)
	{
		// ��� �ٷ� ���� �����ϴ� ���
		if (curr == header)
		{
			newnode->data = data;
			newnode->next = NULL;
			header->head = newnode;
			printf("��� �ٷ� ������ ��带 �����Ͽ����ϴ�.");
			printf("\n");
		}
		// �Է� ������ ��尡 NULL�� ���
		else if (pn == NULL)
		{
			printf("������ ��ġ�� ã�� �� �����ϴ�.");
			printf("\n");
		}
		// pn�� �Ϲ����� ����� ���
		else
		{
			newnode->data = data;
			// ����� next�� �� ������� next�� �־� ������ ������� ���� ���� ����
			newnode->next = curr->next;
			curr->next = newnode; // ������ ����� ����
			printf("%d��° ���� %d��° ��� ���̿� �� ��� ���� �Ϸ�\n", n, n + 1);
			printf("\n");
		}
	}
}

// ���� ��� �߰�
Node* RearInsertNode(HeadNode* header, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode != NULL)
	{
		// data�� next�� �ϴ� �ʱ�ȭ ��
		newnode->data = data;
		newnode->next = NULL;

		// �� ���� �� ����� ���� ó��
		// ��� �ٷ� ������ �߰��ϴ� ���
		if (header->head == NULL)
		{
			header->head = newnode;
		}
		// ��� �ٷ� ���� ��尡 �����ϴ� ���
		else if (header->head != NULL)
		{
			Node* curr = header->head;
			while (curr->next != NULL) // curr�� �� ������ ���
			{
				curr = curr->next; // ó������ ��ȸ�Ͽ� ������ ��忡 ����
			}
			curr->next = newnode; // ������ּҸ� curr�� next�� ����
		}
	}
	return newnode;
}

// ��ü ���
void PrintNode(HeadNode* header)
{
	int n = 1;
	Node* curr = header->head; // curr�� ù��° ���� ����

	// ���� ����� �ִ� ���
	if (curr == NULL)
	{
		printf("��� ��� : ���� ����� �����մϴ�.\n");
		printf("\n");
	}
	// ��� ���� ��尡 �ִ� ���
	else
	{
		while (curr != NULL)
		{
			printf("��� ��� : %d��° ����� ���� : %d\n", n++, curr->data);
			curr = curr->next; // ��������带 ã���� ���� ��ȸ
		}
		printf("\n");
	}
}

// ���Ḯ��Ʈ�� ��ü ��� ����
void AllDeleteNode(HeadNode* header)
{
	// ���� ����� �ִ� ���
	if (header->head == NULL)
	{
		printf("���� ���� : ���� ����� �����մϴ�.\n");
		printf("\n");
	}

	// ��� ���� ��尡 �����ϴ� ���
	int n = 1;
	Node* temp;
	Node* curr = header->head;
	while (curr != NULL)
	{
		temp = curr->next; // ���� ��带 ����� ���� �ش� ����� next�� temp�� ����
		printf("���� ���� : %d��° ��带 �����մϴ�.\n", n++);
		free(curr); // curr �� ���� �Ҵ�� ��� ����(curr�� �״�� ����)
		curr = temp; // ������ ����� ���� ��带 ����Ű�� curr
	}
	header->head = NULL; // ��� ���� �� �� ����� ���� ó��
	printf("\n");
}

// �����͸� ���� ��� �˻�
Node* SearchNode(HeadNode* header, int data)
{
	int n = 1;
	Node* curr = header->head;
	while (curr != NULL)
	{
		if (curr->data == data) break; // �ش� data�� ���� ��带 ����Ű�� �Ǹ� Ż��
		curr = curr->next;
		n++;
	}
	if (curr == NULL) printf("�˻� ���� : �ش��ϴ� data�� ��� ���� �����ϴ�.\n");
	else printf("�˻� ��� : %d��(��) ���� ���� %d��° ����Դϴ�.\n", data, n);
	printf("\n");
	return curr;
}

// �� ��� ����
void DeleteNode(HeadNode* header, Node* node)
{
	int n = 2;

	// �ش� ��尡 �������� �ʴ� ���
	if (node == NULL)
	{
		printf("���� ���� : ������ ��尡 �����ϴ�.\n");
		printf("\n");
	}
	// ���� ����� �����ϴ� ���
	else if (header->head == NULL)
	{
		printf("���� ���� : ���� ����� �����մϴ�.\n");
		printf("\n");
	}
	else
	{
		// ��� �ٷ� ���� ��带 �����ϴ� ���
		if (header->head == node)
		{
			printf("���� ���� : 1��° ��带 �����մϴ�.\n");
			printf("\n");
			header->head = node->next; // ����� ���� ����� ���� ��带 ���� 
			free(node);
		}
		// �ι�° ��� �� �� ���� ��带 �����ϴ� ���
		else
		{
			Node* curr = header->head;
			while (curr != NULL)
			{
				if (curr->next == node) break; // ������ ����� �� ��带 Ž��
				curr = curr->next;
				n++;
			}
			printf("���� ���� : %d��° ��带 �����մϴ�.\n", n);
			printf("\n");
			curr->next = node->next; // �� ���� ���� ��带 ����
			free(node); // ���� ��ǥ���� ��� ����
		}
	}
}

