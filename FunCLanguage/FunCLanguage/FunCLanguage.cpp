#include <stdio.h>

void Decimal4Binary(int value);

int main()
{
	printf("10進数→10進数：　%d\n", 255);			// 10進数
	printf(" 2進数→10進数：　%d\n", 0b11111111);	// 2進数
	printf("16進数→10進数：　%d\n", 0xff);			// 16進数

	printf("\n");

	int value = 255;
	printf("10進数→10進数：　%d\n", value);		// 10進数
	printf("10進数→ 2進数：　");
	Decimal4Binary(value);							// 2進数
	printf("10進数→16進数：　%x\n", value);		// 16進数

	return 0;
}

void Decimal4Binary(int value)
{
	int index = 0;
	while (0 < value)
	{
		if (index != 0 && (index % 4) == 0)printf(",");
		printf("%d", value % 2);
		value = value / 2;
		index++;
	}
	printf("\n");
}