#include <stdio.h>
//퀵 정렬 : 대표적인 분할 정복 알고리즘
//          정렬이 안된 구조에서 사용하면 빠름
//          1. 원소들 중에서 pivot을 고른다.
//          2. pivot 기준으로 앞에는 작은 값, 뒤에는 큰 값들을 위치시킨다(분할).
//          3. 분할된 작은 리스트를 재귀적으로 동작을 시킨다(정복).
//          4. 정렬된 작은 리스트들을 결합한다(결합).

void QuickSort(int* pary, int left, int right);

int main()
{
	int ary[] = { 3, 5, 2, 4, 7, 1, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);

	QuickSort(ary, 0, size - 1);

	return 0;
}

void QuickSort(int* pary, int left, int right)
{
	if (left >= right) return;
	int pivot = left;
	int lleft = pivot + 1;
	int lright = right;
	int temp, i;

	while (lleft <= lright) // lleft와 lright가 교체가 안될 때 까지
	{
		// pivot 왼쪽이 정렬된 경우 lleft는 오른쪽으로 이동
		while (pary[lleft] <= pary[pivot]) lleft++;
		// pivot 오른쪽이 정렬된 경우 lright는 왼쪽으로 이동
		while (pary[lright] >= pary[pivot] && lright > left) lright--;

		if (lleft > lright)
		{
			temp = pary[lright];
			pary[lright] = pary[pivot];
			pary[pivot] = temp;
		}
		else
		{
			temp = pary[lright];
			pary[lright] = pary[lleft];
			pary[lleft] = temp;
		}
	}
	for (i = 0; i < right + 1; i++)
	{
		printf("%d ", pary[i]);
	}
	printf("\n");
	QuickSort(pary, left, lright - 1); // pivot 기준 왼쪽 정리
	QuickSort(pary, lright + 1, right); // pivot 기준 오른쪽 정리
}