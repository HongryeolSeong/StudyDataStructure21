#include <stdio.h>

int main()
{
	int a = 0;
	int i;

	while (1)
	{
		printf("2~9사이의 정수를 입력하세요.");
		scanf("%d", &a);

		if (a == -1)
		{
			break;
		}

		if (a > 1 && a < 10)
		{
			for (i = 1; i < 10; i++)
			{
				printf("%d * %d = %d\n", a, i, a * i);
			}
		}
		else if (a < 2 || a > 9)
		{
			printf("다시 입력하세요.");
			printf("\n");
		}

		printf("\n");
	}

	return 0;
}