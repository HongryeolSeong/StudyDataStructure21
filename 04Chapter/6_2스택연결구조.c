#include <stdio.h>
#include <stdbool.h>

typedef struct snode
{
	int data;
	struct snode* link;
} SNode;

typedef struct
{
	SNode* topstk;
} TStack;

TStack* CreateHead();
int IsEmpty(TStack* ptstack);
void Push(TStack* ptstack, int data);
int Pop(TStack* ptstack);
int Peek(TStack* ptstack);
void PrintStack(TStack* ptstack);

int main()
{
	TStack* h = CreateHead();

	Push(h, 10);
	Push(h, 20);
	Push(h, 30);
	PrintStack(h);

	return 0;
}

TStack* CreateHead()
{
	TStack* t = (TStack*)malloc(sizeof(TStack));
	if (t != NULL)
	{
		t->topstk = NULL;
	}
	else return t;
}

int IsEmpty(TStack* ptstack)
{
	if (ptstack->topstk == NULL) return true;
	else return false;
}

void Push(TStack* ptstack, int data)
{
	SNode* newNode = (SNode*)malloc(sizeof(SNode));
	if (newNode == NULL) return;
	newNode->data = data;
	newNode->link = ptstack->topstk;
	ptstack->topstk = newNode;
}

int Pop(TStack* ptstack)
{
	int data;
	SNode* temp;
	if (IsEmpty(ptstack))
	{
		printf("STACK is Empty");
		return;
	}
	else
	{
		data = ptstack->topstk->data;
		temp = ptstack->topstk;
		ptstack->topstk = ptstack->topstk->link;
		free(temp);
		return data;
	}
}

int Peek(TStack* ptstack)
{
	if (IsEmpty(ptstack))
	{
		printf("\n\n STACK is Empty! \n");
		return;
	}
	else return ptstack->topstk->data;
}

void PrintStack(TStack* ptstack)
{
	SNode* curr = ptstack->topstk;

	printf("\n STACK [ ");
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->link;
	}
	printf("] ");
}