#include <stdio.h>

void Sample2_1();
void Sample2_2();

// 3・・・データ型の種類のサンプル
int main()
{
	Sample2_1();
	Sample2_2();

	return 0;
}

// 各種書式指定した出力
void Sample2_1()
{
	printf("%d\n", 100);		// 10進整数
	printf("%f\n", 1.2f);		// float型実数
	printf("%lf\n", 3.14);		// double型実数
	printf("%c\n", 'A');		// 文字
	printf("%s\n", "Hello");	// 文字列
	printf("%o\n", 0100);		// 8進整数
	printf("%x\n", 0x100);		// 16進整数
	printf("\n");
}

// データ型の違う値同士で計算する
void Sample2_2()
{
	char ch = 11;			// char型
	int it = 22;			// int型
	short sh = 33;			// short型
	long lg = 44l;			// long型
	float fl = 55.5f;		// float型
	double dbl = 66.6666;	// double型

	printf("char  + int    :%d\n", ch + it);
	printf("short + long   :%d\n", sh + lg);
	printf("int   + float  :%f\n", it + fl);
	printf("int   + double :%lf\n", it + dbl);
	printf("float + double :%lf\n", fl + dbl);
	printf("\n");
}