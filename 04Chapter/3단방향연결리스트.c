#include <stdio.h>

typedef struct node
{
	int data;
	struct node* next;
} Node;

typedef struct
{
	Node* head; // Node�� ����ų �� �ִ� ���
} HeadNode; // ���

HeadNode* CreateHead();
Node* PreInsertNode(HeadNode* header, int data);
Node* RearInsertNode(HeadNode* header, int data);
void PrintNode(HeadNode* header);
void AllDeleteNode(HeadNode* header);
Node* SearchNode(HeadNode* header, int data);
void DeleteNode(HeadNode* header, Node* node);
void MidInsertNode(HeadNode* header, Node* pn, int data);

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
	//sn = SearchNode(h, 30);
	//AllDeleteNode(h);
	//printf("�ش� ��� : %u, %d\n", &sn, sn->data);*/
	DeleteNode(h, n3);
	//PrintNode(h);
	//MidInsertNode(h, n1, 7);
	//sn = SearchNode(h, 7);
	PrintNode(h);

	return 0;
}

//����� �����ϴ� �Լ�
HeadNode* CreateHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL; // ������ ����. ������ : NULL�� h�� ����Ű�� ���

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
		else if (header->head != NULL) // h���� ��尡 �ִ� ���
		{
			Node* curr = header->head; // curr�� �� ����� �ٷ� �� ���
			while (curr->next != NULL)
			{
				curr = curr->next; // n1���� n2�� curr�� �̵�
			}
			curr->next = newnode; // while�� ���� curr�� ������Ų �� ������ּҸ� curr�� next�� ����
		}
	}
	return newnode;
}

void PrintNode(HeadNode* header)
{
	int n = 1;
	Node* curr = header->head; // curr�� ù��° ���� ����
	if (curr == NULL)
	{
		printf("��� ��� : ���� ��常 �����մϴ�.\n");
		printf("\n");
	}
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

void AllDeleteNode(HeadNode* header)
{
	if (header->head == NULL)
	{
		printf("���� ���� : ���� ��常 �����մϴ�.\n");
		printf("\n");
	}
	int n = 1;
	Node* temp;
	Node* curr = header->head;
	while (curr != NULL)
	{
		temp = curr->next; // ���� ��带 ����� ���� �ش� ����� next�� temp�� ����
		printf("���� ���� : %d��° ��带 �����մϴ�.\n", n++);
		free(curr);
		curr = temp;
	}
	header->head = NULL;
	printf("\n");
}

Node* SearchNode(HeadNode* header, int data)
{
	int n = 2;
	Node* curr = header->head;
	while (curr != NULL)
	{
		if (curr->data == data) break;
		curr = curr->next;
		n++;
	}
	if (curr == NULL) printf("�˻� ���� : �ش��ϴ� data�� ��� ���� �����ϴ�.\n");
	else printf("�˻� ��� : %d��(��) ���� ���� %d��° ����Դϴ�.\n", data, n);
	printf("\n");
	return curr;
}

void DeleteNode(HeadNode* header, Node* node)
{
	int n = 2;

	if (node == NULL)
	{
		printf("���� ���� : ������ ��尡 �����ϴ�.\n");
		printf("\n");
	}
	else if (header->head == NULL)
	{
		printf("���� ���� : ���� ��常 �����մϴ�.\n");
		printf("\n");
	}
	else
	{
		if (header->head == node) // ��� �ٷ� ���� ��常 �����ϴ� ���
		{
			printf("���� ���� : 1��° ��带 �����մϴ�.\n");
			printf("\n");
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
				n++;
			}
			printf("���� ���� : %d��° ��带 �����մϴ�.\n", n);
			printf("\n");
			curr->next = node->next;
			free(node);
		}
	}
}

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
	// curr = ������ ��� ��ġ �ٷ� �� ���

	// curr ������ �� ��� �����ϱ�
	Node* newnode = (Node*)malloc(sizeof(Node)); // ����� ����
	if (newnode != NULL)
	{
		if (curr == header)
		{
			newnode->data = data;
			newnode->next = NULL;
			header->head = newnode;
			printf("��� �ٷ� ������ ��带 �����Ͽ����ϴ�.");
			printf("\n");
		}
		else if (pn == NULL)
		{
			printf("������ ��ġ�� ã�� �� �����ϴ�.");
			printf("\n");
		}
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