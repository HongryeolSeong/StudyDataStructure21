#include <stdio.h>

void main()
{
	char s1[80];
	int i;

	printf("\n���ڿ��� �Է��ϼ��� : ");
	gets(s1);
	/*for (i = 0; i < strlen(s1); i++)
	{
		printf("%c", s1[i]);
	}*/
	puts(s1);
	printf("\n");
	printf("�Էµ� ���ڿ� ���̴� : %d", strlen(s1));

	getchar();
}