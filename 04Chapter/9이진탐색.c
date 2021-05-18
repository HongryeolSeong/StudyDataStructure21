#include <stdio.h>
//���ĵ� ����� ����Ž��

Bearch(int* pary, int sz, int tg);

int main()
{
	int index;
	//int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int ary[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(ary) / sizeof(ary[0]);

	index = BSearch(ary, size, 4);
	if (index == -1) printf("Ž�� ����!\n");
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
			if (tg > pary[mid]) first = mid + 1; // �߰����� tg�� ū���
			else last = mid - 1; // �߰����� tg�� �������
		}
	}

	return -1;
}