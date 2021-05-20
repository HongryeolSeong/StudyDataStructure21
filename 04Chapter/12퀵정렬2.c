










#include <stdio.h>

void quickSort(int* pary, int left, int right);

int main()
{
	int size;
	int ary[] = { 3, 5, 2, 4, 7, 6, 1, 8 };
	size = sizeof(ary) / sizeof(ary[0]);
	printf("ary[] : 3, 5, 2, 4, 7, 6, 1, 8 \n\n");
	quickSort(ary, 0, size - 1);
	return 0;
}

void quickSort(int* pary, int left, int right)
{
	int lidx = left, ridx = right; // li = left = 0, ri = right = size - 1, li�� lr�� index�� ��Ÿ����.
	int temp;
	int pivot = (left + right) / 2; // n/2�� �Ǻ��� �����Ѵ�.
	printf("pivot = index : %d, value : %d\n", pivot, pary[pivot]);
	while (lidx <= ridx) { // li�� ri�� �����Ǳ� ������ �����Ѵ�.
		while (pary[lidx] < pary[pivot]) lidx++; // �Ǻ��� ���� ����Ʈ �� ���� ���� ���
		while (pary[ridx] > pary[pivot]) ridx--; // �Ǻ��� ������ ����Ʈ �� ū ���� ���
		if (lidx <= ridx) { // ������ ������ �Ǹ�(lidx == ridx �̸� pivot ���̴�.)
			temp = pary[ridx]; // ã�� ����Ʈ�� �� ���� ��ȯ�Ͽ� �����Ѵ�.
			pary[ridx] = pary[lidx];
			pary[lidx] = temp;
			printf("%d : %d\n", temp, pary[ridx]);
			lidx++;
			ridx--;
		}
	}
	for (int i = 0; i <= right; i++) printf("%3d", pary[i]);
	printf("\n");
	if (left < ridx) quickSort(pary, left, ridx);
	if (lidx < right) quickSort(pary, lidx, right);
}
