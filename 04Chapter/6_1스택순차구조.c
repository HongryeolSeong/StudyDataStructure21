#include <stdio.h>
#include <stdbool.h> // 이거 사용시
// 순차 구조 스택 : 순차 구조(배열)을 이용한 스택

#define STACK_SZ 3
//#define TRUE 1 // 이거 생략 가능
//#define TRUE 2

int IsEmpty(); // 공백 체크
int IsFull();  // 포화 체크
void Push(int); // 스택에 삽입
int Pop(); // 스택에서 빼기
int Peek(); // 맨 위 값 확인
void PrintStack(); // 전체 스택 출력

int stack[STACK_SZ]; // 스택 배열
int top = -1; // 스택의 위치를 확인, 항상 맨 위를 가리킨다.

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

// 공백 체크
int IsEmpty()
{
	if (top <= -1) return true;
	else return false;
}

// 포화 체크
int IsFull()
{
	if (top >= STACK_SZ - 1) return true; // 포화상태일 경우 top=STACK_SZ - 1
	else return false;
}

// 스택에 삽입
void Push(int data)
{
	if (IsFull()) // IsFull이 참일 경우
	{
		printf("\n\n Stack Overflow! \n");
		return;
	}
	else
	{
		stack[++top] = data; // top=-1일 때 stack[0]에 값 대입
	}
}

// 스택에서 빼기
int Pop()
{
	if (IsEmpty())
	{
		printf("\n\n STACK Underflow! \n");
		return;
	}
	else
	{
		return stack[top--]; // 스택 값 하나 뺀 후, top을 하나 마이너스
	}
}

// 최상위 값 확인
int Peek()
{
	if (IsEmpty())
	{
		printf("\n\n STACK is Empty! \n");
		return;
	}
	else return stack[top]; // 포화상태일 경우 top=2
}

// 전체 출력
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