#include <stdio.h>

void main()
{
	int i, n = 0, * ptr;
	int(*pptr)[4]; // 2���� �迭�� sale�� ��� ���� �迭 ������ ����
	int sale[2][4] = { {63, 84, 140, 130},
						{157, 209, 251, 312} };

	pptr = sale; // pptr�� sale ����

	ptr = &sale[0][0];
	for (i = 0; i < 8; i++)
	{
		printf("\n address : %u  sale %d = %d", ptr, i, *ptr);
		ptr++; // 4byte�� ����
	} // C �����Ϸ��� �� �켱 ���� ��� ���

	//printf("\n%d", ptr[1][1]); // 2���� �迭�ε� �׳� �����ͷ� ���������Ƿ� ��� �Ұ�
	printf("\n\n %d", pptr[1][1]);
	printf("\n\n %u", pptr + 1);

	getchar();
}