#include <stdio.h>
// �������� : �ι�° �ڷ���� �� �ڷḦ ���Ͽ� ����

void InsertionSort(int* pary, int sz);
void PrintAry(int* pary, int sz);

int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);

	InsertionSort(ary, size);
	//PrintAry(ary, size);

	return 0;
}

void InsertionSort(int* pary, int sz)
{
	int i, j, k, temp;

	for (i = 1; i < sz; i++) // �ι�° ��Һ��� ������ ��ұ��� �ݺ�
	{
		for (j = i; j > 0; j--) // �ش� ��Һ��� �ι�° ��ұ��� �ݺ�
		{
			if (pary[j] < pary[j - 1])
			{
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
		printf("\n  %d �ܰ� : ", i);
		for (k = 0; k < sz; k++) // ���� �ܰ踦 �ð�ȭ
		{
			printf(" %d", pary[k]); // �ش� �ܰ賡���� ���� ��� ǥ��
		}
	}
}

void PrintAry(int* pary, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("ary[%d] : %d\n", i, pary[i]);
	}
}