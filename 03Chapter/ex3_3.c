#include <stdio.h>

void main()
{
	int i, n = 0, * ptr;
	int*(* ppptr)[2][4]; // 3���� �迭�� sale�� ���� ���� �迭 ������
	int sale[2][2][4] = { {{63, 84, 140, 130}, // 1��
							{157, 209, 251, 312}},
		{{59, 80, 130, 135}, // 2��
		{149, 187, 239, 310}} };
	ppptr = sale;

	ptr = &sale[0][0][0];
	for (i = 0; i < 16; i++)
	{
		printf("\n address: %u  sale %2d = %3d", ptr, i, *ptr);
		ptr++;
	}

	printf("\n\n %d", ppptr[0][0][0]); // sale[0][0][0]�� ���

	getchar();
}