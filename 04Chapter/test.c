#include <stdio.h>

int main()
{
	int A, B;
	double res;

	scanf("%d%d", &A, &B);
	printf("%d\n", A + B);
	res = (double)A / (double)B;
	printf("%.9lf", res);

	return 0;
}