#include <stdio.h>

void main()
{
	char s1[80];
	int i;

	printf("\n문자열을 입력하세요 : ");
	gets(s1);
	/*for (i = 0; i < strlen(s1); i++)
	{
		printf("%c", s1[i]);
	}*/
	puts(s1);
	printf("\n");
	printf("입력된 문자열 길이는 : %d", strlen(s1));

	getchar();
}