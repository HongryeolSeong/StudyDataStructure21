#include <stdio.h>

void main()
{
	int i, n = 0, * ptr;
	int(*pptr)[4]; // 2차원 배열인 sale을 담기 위한 배열 포인터 선언
	int sale[2][4] = { {63, 84, 140, 130},
						{157, 209, 251, 312} };

	pptr = sale; // pptr에 sale 담음

	ptr = &sale[0][0];
	for (i = 0; i < 8; i++)
	{
		printf("\n address : %u  sale %d = %d", ptr, i, *ptr);
		ptr++; // 4byte씩 증가
	} // C 컴파일러는 행 우선 순서 방법 사용

	//printf("\n%d", ptr[1][1]); // 2차원 배열인데 그냥 포인터로 연결했으므로 출력 불가
	printf("\n\n %d", pptr[1][1]);
	printf("\n\n %u", pptr + 1);

	getchar();
}