#include <stdio.h>

void main()
{
	int i, j, k;
	char student[2][3][20];
	for (i = 0; i < 2; i++)
	{
		printf("\n �л� %d�� �̸� : ", i + 1);
		gets(student[i][0]);
		printf(" �л� %d�� �а� : ", i + 1);
		gets(student[i][1]);
		printf(" �л� %d�� �й� : ", i + 1);
		gets(student[i][2]);
	}

	for (i = 0; i < 2; i++)
	{
		printf("\n\n �л� %d", i + 1);
		for (j = 0; j < 3; j++)
		{
			printf("\n\t");
			for (k = 0; student[i][j][k]; k++)
			{
				printf("%c", student[i][j][k]);
			}
		}
	}

	getchar();
}