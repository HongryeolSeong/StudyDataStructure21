#include <stdio.h>

long int fact(int);

void main()
{
	int n, result;
	printf("\n ������ �Է��ϼ��� : ");
	scanf("%d", &n);
	result = fact(n);
	printf("\n\n %d�� ���丮�� ���� %ld�Դϴ�.\n", n, result);
	getchar(); getchar();
}

long int fact(int n)
{
	int value;
	if (n <= 1) // ���� ����(��� Ȱ��� �ʼ��� �� ��)
	{
		printf("\n fact(1) �Լ� ȣ��!");
		printf("\n fact(1) �� 1 ��ȯ!!");
		return 1; // �׻� �������� 1!�̰�, ��� ȣ�� ����
	}
	else
	{
		printf("\n fact(%d) �Լ� ȣ��!", n);
		value = (n * fact(n - 1)); // ��� ȣ��
		printf("\n fact(%d) �� %ld ��ȯ!!", n, value);
		return value;
	}
}