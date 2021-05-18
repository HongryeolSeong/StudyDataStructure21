#include <stdio.h>
//�� ���� : ��ǥ���� ���� ���� �˰���
//          ������ �ȵ� �������� ����ϸ� ����
//          1. ���ҵ� �߿��� pivot�� ����.
//          2. pivot �������� �տ��� ���� ��, �ڿ��� ū ������ ��ġ��Ų��(����).
//          3. ���ҵ� ���� ����Ʈ�� ��������� ������ ��Ų��(����).
//          4. ���ĵ� ���� ����Ʈ���� �����Ѵ�(����).

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

	while (lleft <= lright) // lleft�� lright�� ��ü�� �ȵ� �� ����
	{
		// pivot ������ ���ĵ� ��� lleft�� ���������� �̵�
		while (pary[lleft] <= pary[pivot]) lleft++;
		// pivot �������� ���ĵ� ��� lright�� �������� �̵�
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
	QuickSort(pary, left, lright - 1); // pivot ���� ���� ����
	QuickSort(pary, lright + 1, right); // pivot ���� ������ ����
}