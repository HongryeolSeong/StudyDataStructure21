#include <stdio.h>
#include <stdbool.h> // �̰� ����

#define STACK_SZ 3
//#define TRUE 1 // �̰� ���� ����
//#define TRUE 2

int IsEmpty(); // ����üũ
int IsFull();  // ��ȭüũ
void Push(int); // ���ÿ� ����
int Pop(); // ���ÿ��� ����
int Peek(); // �� �� �� Ȯ��
void PrintStack(); // ��ü ���� ���

int stack[STACK_SZ];
int top = -1; // ������ ��ġ�� Ȯ��, �׻� �� ���� ����Ų��.

int main()
{
	Push(10);
	Push(20);
	Push(30);
	Pop();

	PrintStack();

	return 0;
}

int IsEmpty()
{
	if (top <= -1) return true;
	else return false;
}

int IsFull()
{
	if (top >= STACK_SZ - 1) return true;
	else return false;
}

void Push(int data)
{
	if (IsFull())
	{
		printf("\n\n Stack Overflow! \n");
		return;
	}
	else
	{
		stack[++top] = data;
	}
}

int Pop()
{
	if (IsEmpty())
	{
		printf("\n\n STACK Underflow! \n");
		return;
	}
	else
	{
		return stack[top--];
	}
}

int Peek()
{
	if (IsEmpty())
	{
		printf("\n\n STACK is Empty! \n");
		return;
	}
	else return stack[top];
}

void PrintStack()
{
	int i;

	if (!IsEmpty())
	{
		printf("\n STACK [ ");
		for (i = 0; i <= top; i++)
		{
			printf("%d ", stack[i]);
		}
		printf("] ");
	}
}