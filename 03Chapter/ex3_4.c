#include <stdio.h>
#define MAX(a, b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct
{
	int degree; // 다항식의 차수
	float coef[MAX_DEGREE]; // 다항식의 각 항 계수의 배열
} polynomial;

polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial);

void main()
{
	polynomial A = { 3, { 4, 3, 5, 0 } }; // 4x^3 + 3x^2 + 5x^1 + 0x^0
	polynomial B = { 4, { 3, 1, 0, 2, 1 } }; // 3x^4 + 1x^3 + 0x^2 + 2x^1 + 1x^0

	polynomial C;
	C = addPoly(A, B);

	printf("\n A(x) ="); 
	printPoly(A);
	printf("\n B(x) ="); 
	printPoly(B);
	printf("\n C(x) ="); 
	printPoly(C);

	getchar();
}

polynomial addPoly(polynomial A, polynomial B)
{
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree; // 3, 4
	C.degree = MAX(A.degree, B.degree); // 4

	while (A_index <= A.degree && B_index <= B.degree) // 3차 ~ 0차 AND 4차 ~ 0차
	{
		if (A_degree > B_degree) // A의 항이 B의 항보다 차수가 높은 경우
		{
			C.coef[C_index++] = A.coef[A_index++]; // 결과 다항식의 항에 A의 항을 대입
			A_degree--; // 다음 차항으로 내려감
		}
		else if (A_degree == B_degree) // B항의 차수 = A항의 차수인 경우
		{
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++]; // 두 항을 더하여 결과 다항식 항에 대입
			A_degree--; // 다음 차항으로 내려감
			B_degree--;
		}
		else // B의 항이 A의 항보다 차수가 높은 경우
		{
			C.coef[C_index++] = B.coef[B_index++]; // 결과 다항식의 항에 B의 항을 대입
			B_degree--; // 다음 차항으로 내려감
		}
	}
	return C;
}

void printPoly(polynomial P)
{
	int i, degree;
	degree = P.degree; // 구조체의 차수를 대입 ex)a다항식의 경우 3대입

	for (i = 0; i <= P.degree; i++)
	{
		printf("%3.0fx^%d", P.coef[i], degree--); // 고차항부터 차례로 출력
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}