#include <stdio.h>
#include <stdbool.h>
// ����ť
#define SIZE 6

int IsEmpty();
int IsFull();
void enQueue(int); // ť�� ����
int deQueue(); // ť���� ����

int rear = 0; // �Ա�
int front = 0; // �ⱸ
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
	// rear�� 0~5
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
		rear = rear % SIZE; // rear�� 0~5������ ���ڸ� �ǰԲ�
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

