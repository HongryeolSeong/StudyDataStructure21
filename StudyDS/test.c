#include <stdio.h>

int main()
{
	int i;
	int A[5] = { 1, 2, 3 };
	char B[5] = { 'a', 'b', 'c' };

	for (i = 0; i < 5; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("%c ", B[i]);
	}

	return 0;
}