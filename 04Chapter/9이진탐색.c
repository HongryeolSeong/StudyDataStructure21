#include <stdio.h>
//정렬된 경우의 이진탐색

Bearch(int* pary, int sz, int tg);

int main()
{
	int index;
	//int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int ary[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(ary) / sizeof(ary[0]);

	index = BSearch(ary, size, 4);
	if (index == -1) printf("탐색 실패!\n");
	else printf("%d", index);

	return 0;
}

int BSearch(int* pary, int sz, int tg)
{
	int first = 0;
	int last = sz - 1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (tg == pary[mid]) return mid;
		else
		{
			if (tg > pary[mid]) first = mid + 1; // 중간보다 tg가 큰경우
			else last = mid - 1; // 중간보다 tg가 작은경우
		}
	}

	return -1;
}