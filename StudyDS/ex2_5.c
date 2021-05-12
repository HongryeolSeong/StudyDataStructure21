#include <stdio.h>

void main()
{
	int i, length = 0;
	char str[50];
	
	printf("\n문자열을 입력하세요 : ");
	gets(str);
	printf("\n입력된 문자열은 \n \"");
	for (i = 0; str[i]; i++) // str[i]의 끝에는 널문자 = 0이 있으므로 거짓이 되어 for문 종료
	{
		printf("%c", str[i]);
		length += 1;
	}
	printf("\" \n입니다.");
	printf("\n\n입력된 문자열의 길이 = %d \n", length);

	getchar();
}