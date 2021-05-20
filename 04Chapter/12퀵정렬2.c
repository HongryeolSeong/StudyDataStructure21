










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
	int lidx = left, ridx = right; // li = left = 0, ri = right = size - 1, li와 lr은 index를 나타낸다.
	int temp;
	int pivot = (left + right) / 2; // n/2로 피봇을 설정한다.
	printf("pivot = index : %d, value : %d\n", pivot, pary[pivot]);
	while (lidx <= ridx) { // li와 ri가 교차되기 전까지 실행한다.
		while (pary[lidx] < pary[pivot]) lidx++; // 피봇의 왼쪽 리스트 중 작은 값은 통과
		while (pary[ridx] > pary[pivot]) ridx--; // 피봇의 오른쪽 리스트 중 큰 값은 통과
		if (lidx <= ridx) { // 정렬할 조건이 되면(lidx == ridx 이면 pivot 값이다.)
			temp = pary[ridx]; // 찾은 리스트의 두 값을 교환하여 정렬한다.
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
