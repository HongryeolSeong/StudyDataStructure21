#include <stdio.h>
#include <string.h>

struct employee
{
	char name[10];
	int year;
	int pay;
};

void main()
{
	struct employee Lee;
	struct employee* Sptr = &Lee;
	strcpy(Sptr->name, "�̼���");
	Sptr->year = 2015;
	Sptr->pay = 5900;

	printf("\n �̸� : %s", Sptr->name);
	printf("\n �Ի� : %d", Sptr->year);
	printf("\n ���� : %d", Sptr->pay);

	getchar();
}