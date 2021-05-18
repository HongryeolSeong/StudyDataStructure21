#include <stdio.h>
// 삽입정렬 : 두번째 자료부터 앞 자료를 비교하여 정렬

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

	for (i = 1; i < sz; i++) // 두번째 요소부터 마지막 요소까지 반복
	{
		for (j = i; j > 0; j--) // 해당 요소부터 두번째 요소까지 반복
		{
			if (pary[j] < pary[j - 1])
			{
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
		printf("\n  %d 단계 : ", i);
		for (k = 0; k < sz; k++) // 정렬 단계를 시각화
		{
			printf(" %d", pary[k]); // 해당 단계끝난후 정렬 결과 표시
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