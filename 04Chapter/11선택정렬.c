#include <stdio.h>
// �������� : 0������ �ּҰ��̶�� �����ϰ�
//            ������ ���ҵ�� ���Ͽ� ��ü�Ѵ�.
//            -> �ּڰ��� ���ʷ� 0����, 1����, 2���濡 �ִ½�

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

	for (i = 0; i < sz - 1; i++) // 9�� ��� �� ó������ ������ �� ��ұ��� �ݺ�
	{
		min = i; // i���� �ּڰ����� ����
		for (j = i + 1; j < sz; j++)
		{
			if (pary[min] > pary[j]) min = j;
			// �� �ּڰ����� ���� ���� �ε����� ã��
		}
		temp = pary[min];
		pary[min] = pary[i];
		pary[i] = temp;

		printf("\n %d�ܰ� : ", i + 1);
		for (k = 0; k < sz; k++)
		{
			printf("%d ", pary[k]);
		}
	}
}
