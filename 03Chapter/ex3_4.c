#include <stdio.h>
#define MAX(a, b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct
{
	int degree; // ���׽��� ����
	float coef[MAX_DEGREE]; // ���׽��� �� �� ����� �迭
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

	while (A_index <= A.degree && B_index <= B.degree) // 3�� ~ 0�� AND 4�� ~ 0��
	{
		if (A_degree > B_degree) // A�� ���� B�� �׺��� ������ ���� ���
		{
			C.coef[C_index++] = A.coef[A_index++]; // ��� ���׽��� �׿� A�� ���� ����
			A_degree--; // ���� �������� ������
		}
		else if (A_degree == B_degree) // B���� ���� = A���� ������ ���
		{
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++]; // �� ���� ���Ͽ� ��� ���׽� �׿� ����
			A_degree--; // ���� �������� ������
			B_degree--;
		}
		else // B�� ���� A�� �׺��� ������ ���� ���
		{
			C.coef[C_index++] = B.coef[B_index++]; // ��� ���׽��� �׿� B�� ���� ����
			B_degree--; // ���� �������� ������
		}
	}
	return C;
}

void printPoly(polynomial P)
{
	int i, degree;
	degree = P.degree; // ����ü�� ������ ���� ex)a���׽��� ��� 3����

	for (i = 0; i <= P.degree; i++)
	{
		printf("%3.0fx^%d", P.coef[i], degree--); // �����׺��� ���ʷ� ���
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}