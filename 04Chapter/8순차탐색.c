#include <stdio.h>

int LSearch(int* pary, int sz, int tg);

int main()
{
	int index;
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int size = sizeof(ary) / sizeof(ary[0]);

	index = LSearch(ary, size, 77);
	if (index == -1) printf("찾기 실패!\n");
	else printf("%d\n", index);

	return 0;
}

int LSearch(int* pary, int sz, int tg)
{
	int i;
	for (i = 0; i < sz; i++) 
	{
		if (tg == pary[i]) //tg가 pary[i]와 같을시
		{
			return i; // i 반환
		}
	}
	return -1; // pary[i]에 tg값이 없는 경우 -1 반환
}