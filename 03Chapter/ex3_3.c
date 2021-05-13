#include <stdio.h>

void main()
{
	int i, n = 0, * ptr;
	int*(* ppptr)[2][4]; // 3차원 배열인 sale을 받을 이중 배열 포인터
	int sale[2][2][4] = { {{63, 84, 140, 130}, // 1팀
							{157, 209, 251, 312}},
		{{59, 80, 130, 135}, // 2팀
		{149, 187, 239, 310}} };
	ppptr = sale;

	ptr = &sale[0][0][0];
	for (i = 0; i < 16; i++)
	{
		printf("\n address: %u  sale %2d = %3d", ptr, i, *ptr);
		ptr++;
	}

	printf("\n\n %d", ppptr[0][0][0]); // sale[0][0][0]을 출력

	getchar();
}