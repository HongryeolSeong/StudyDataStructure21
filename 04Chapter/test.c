#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	int score;
	char ox[85];
	int s[100] = { 0 };

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++)
	{
		gets(ox);

		score = 0;

		for (int j = 0; j < strlen(ox); j++)
		{
			if (ox[j] == 'O')
			{
				score++;
				s[j] += score;
			}
			else if (ox[j] == 'X')
			{
				score = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", s[i]);
	}

	return 0;
}