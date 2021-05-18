#include <stdio.h>
#include <stdbool.h>

typedef struct qnode
{
	int data;
	struct qnode* link;
} QNode;

typedef struct
{
	QNode* front;
	QNode* rear;
} HqNode;

HqNode* CreateHead();
int IsEmpty(HqNode* h);
//int IsFull(HqNode* h);
void enQueue(HqNode* h, int data);
int deQueue(HqNode* h);
void PrintQueue(HqNode* h);

int main()
{
	HqNode* h = CreateHead();
	enQueue(h, 10);
	enQueue(h, 20);
	enQueue(h, 30);
	enQueue(h, 40);
	PrintQueue(h);
	//deQueue(h);
	//deQueue(h);
	//deQueue(h);
	//PrintQueue(h);

	return 0;
}

HqNode* CreateHead()
{
	HqNode* h = (HqNode*)malloc(sizeof(HqNode));
	if (h != NULL)
	{
		h->front = NULL;
		h->rear = NULL;
	}
	else return h;
}

int IsEmpty(HqNode* h)
{
	if (h->front == NULL) return true;
	else return false;
}

void enQueue(HqNode* h, int data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		return;
	}
	else
	{
		newNode->data = data;
		newNode->link = NULL;
		if (h->front == NULL)
		{
			h->front = newNode;
			h->rear = newNode;
		}
		else
		{
			h->rear->link = newNode;
			h->rear = newNode;
		}
	}
}

int deQueue(HqNode* h)
{
	int data;
	QNode* temp;
	if (IsEmpty(h))
	{
		printf("\n\n Queue Underflow! \n");
		exit(1);
		return;
	}
	else
	{
		data = h->front->data;
		temp = h->front;
		h->front = temp->link;
		free(temp);
		return data;
	}
}

void PrintQueue(HqNode* h)
{
	QNode* curr = h->front;

	printf(" Linked Queue : [ ");
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->link;
	}
	printf("] \n");
}