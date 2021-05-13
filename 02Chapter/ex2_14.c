#include <stdio.h>

long int fact(int);

void main()
{
	int n, result;
	printf("\n 정수를 입력하세요 : ");
	scanf("%d", &n);
	result = fact(n);
	printf("\n\n %d의 팩토리얼 값은 %ld입니다.\n", n, result);
	getchar(); getchar();
}

long int fact(int n)
{
	int value;
	if (n <= 1) // 기저 조건(재귀 활용시 필수로 둘 것)
	{
		printf("\n fact(1) 함수 호출!");
		printf("\n fact(1) 값 1 반환!!");
		return 1; // 항상 마지막은 1!이고, 재귀 호출 종료
	}
	else
	{
		printf("\n fact(%d) 함수 호출!", n);
		value = (n * fact(n - 1)); // 재귀 호출
		printf("\n fact(%d) 값 %ld 반환!!", n, value);
		return value;
	}
}