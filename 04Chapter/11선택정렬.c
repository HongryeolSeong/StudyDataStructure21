#include <stdio.h>
// 선택정렬 : 0번방을 최소값이라고 가정하고
//            나머지 원소들과 비교하여 교체한다.
//            -> 최솟값을 차례로 0번방, 1번방, 2번방에 넣는식

void SelectSort(int* pary, int sz);

int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);

	SelectSort(ary, size);

	return 0;
}

void SelectSort(int* pary, int sz)
{
	int i, j, k, min, temp;

	for (i = 0; i < sz - 1; i++) // 9개 요소 중 처음부터 마지막 전 요소까지 반복
	{
		min = i; // i방을 최솟값으로 설정
		for (j = i + 1; j < sz; j++)
		{
			if (pary[min] > pary[j]) min = j;
			// 현 최솟값보다 작은 방의 인덱스를 찾음
		}
		temp = pary[min];
		pary[min] = pary[i];
		pary[i] = temp;

		printf("\n %d단계 : ", i + 1);
		for (k = 0; k < sz; k++)
		{
			printf("%d ", pary[k]);
		}
	}
}
