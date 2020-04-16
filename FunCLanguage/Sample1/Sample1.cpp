#include <stdio.h>

void Sample1_1();
void Decimal4Binary(int value);

// 2・・・2進数、16進数のサンプル
int main()
{
	Sample1_1();
	return 0;
}

// n進数の出力
void Sample1_1() 
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
	printf("\n");
}

// 2進数へ変換する場合は書式指定がないため別途関数を用意する
void Decimal4Binary(int value)
{
	int index = 0;

	// 値が0（割り切れなくなる）になるまで繰り返す
	while (0 < value)
	{
		if (index != 0 && (index % 4) == 0)printf(",");
		// 2で割った余りを順次表示する
		printf("%d", value % 2);
		// 2で割った商を格納する
		value = value / 2;
		index++;
	}
	printf("\n");
}