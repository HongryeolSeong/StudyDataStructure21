#include <stdio.h>
#include <stdbool.h>
// 원형큐
#define SIZE 6

int IsEmpty();
int IsFull();
void enQueue(int); // 큐에 삽입
int deQueue(); // 큐에서 삭제

int rear = 0; // 입구
int front = 0; // 출구
int queue[SIZE];

int main()
{
	enQueue(10);
	enQueue(20);
	enQueue(30);

	printf("%d\n", deQueue());
	printf("%d\n", deQueue());
	printf("%d\n", deQueue());
	printf("%d\n", deQueue());

	return 0;
}

int IsEmpty()
{
	if (rear == front) return true;
	else return false;
}

int IsFull()
{
	// rear은 0~5
	if (front == (rear + 1) % SIZE) return true;
	else return false;
}

void enQueue(int data)
{
	if (IsFull())
	{
		printf("\n\n Queue Overflow! \n");
		return;
	}
	else
	{
		rear = rear % SIZE; // rear은 0~5사이의 숫자만 되게끔
		queue[rear] = data;
		rear++;
	}
}

int deQueue()
{
	if (IsEmpty())
	{
		printf("\n\n Queue Underflow! \n");
		exit(1);
		return;
	}
	else
	{
		return queue[front++ % SIZE];
	}
}

