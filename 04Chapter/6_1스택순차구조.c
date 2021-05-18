#include <stdio.h>
#include <stdbool.h> // 이거 사용시

#define STACK_SZ 3
//#define TRUE 1 // 이거 생략 가능
//#define TRUE 2

int IsEmpty(); // 공백체크
int IsFull();  // 포화체크
void Push(int); // 스택에 삽입
int Pop(); // 스택에서 빼기
int Peek(); // 맨 위 값 확인
void PrintStack(); // 전체 스택 출력

int stack[STACK_SZ];
int top = -1; // 스택의 위치를 확인, 항상 맨 위를 가리킨다.

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