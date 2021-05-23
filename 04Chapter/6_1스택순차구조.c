#include <stdio.h>
#include <stdbool.h> // �̰� ����
// ���� ���� ���� : ���� ����(�迭)�� �̿��� ����

#define STACK_SZ 3
//#define TRUE 1 // �̰� ���� ����
//#define TRUE 2

int IsEmpty(); // ���� üũ
int IsFull();  // ��ȭ üũ
void Push(int); // ���ÿ� ����
int Pop(); // ���ÿ��� ����
int Peek(); // �� �� �� Ȯ��
void PrintStack(); // ��ü ���� ���

int stack[STACK_SZ]; // ���� �迭
int top = -1; // ������ ��ġ�� Ȯ��, �׻� �� ���� ����Ų��.

int main()
{
	Push(10); // stack[ 10 ]
	Push(20); // stack[ 10 20 ]
	Push(30); // stack[ 10 20 30 ]
	printf("%d", Peek());
	Pop();    // stack[ 10 20 ]

	PrintStack();

	return 0;
}

// ���� üũ
int IsEmpty()
{
	if (top <= -1) return true;
	else return false;
}

// ��ȭ üũ
int IsFull()
{
	if (top >= STACK_SZ - 1) return true; // ��ȭ������ ��� top=STACK_SZ - 1
	else return false;
}

// ���ÿ� ����
void Push(int data)
{
	if (IsFull()) // IsFull�� ���� ���
	{
		printf("\n\n Stack Overflow! \n");
		return;
	}
	else
	{
		stack[++top] = data; // top=-1�� �� stack[0]�� �� ����
	}
}

// ���ÿ��� ����
int Pop()
{
	if (IsEmpty())
	{
		printf("\n\n STACK Underflow! \n");
		return;
	}
	else
	{
		return stack[top--]; // ���� �� �ϳ� �� ��, top�� �ϳ� ���̳ʽ�
	}
}

// �ֻ��� �� Ȯ��
int Peek()
{
	if (IsEmpty())
	{
		printf("\n\n STACK is Empty! \n");
		return;
	}
	else return stack[top]; // ��ȭ������ ��� top=2
}

// ��ü ���
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