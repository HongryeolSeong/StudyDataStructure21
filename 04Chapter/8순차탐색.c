#include <stdio.h>

int LSearch(int* pary, int sz, int tg);

int main()
{
	int index;
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int size = sizeof(ary) / sizeof(ary[0]);

	index = LSearch(ary, size, 77);
	if (index == -1) printf("ã�� ����!\n");
	else printf("%d\n", index);

	return 0;
}

int LSearch(int* pary, int sz, int tg)
{
	int i;
	for (i = 0; i < sz; i++) 
	{
		if (tg == pary[i]) //tg�� pary[i]�� ������
		{
			return i; // i ��ȯ
		}
	}
	return -1; // pary[i]�� tg���� ���� ��� -1 ��ȯ
}