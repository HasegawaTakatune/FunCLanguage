#include <stdio.h>

void Sample4_1();
void Sample4_2();

// 4・・・ASCIIコードのサンプル
int main()
{
	Sample4_1();
	Sample4_2();
}

// ASCIIコードを使った文字の出力
void Sample4_1() {
	char largeChar = 'A';
	char smallChar;

	// ASCIIコード上の大文字と小文字の差分を取得
	int offset = 'a' - 'A';
	// 大文字に差分を足し合わせることで小文字を取得
	smallChar = largeChar + offset;

	// 文字から大文字小文字を出力
	printf("大文字：%c  小文字：%c\n", largeChar, smallChar);

	// 10進数から大文字小文字を出力
	printf("大文字：%c  小文字：%c\n", 65, 97);

	// 16進数から大文字小文字を出力
	printf("大文字：%c  小文字：%c\n", 0x41, 0x61);
	printf("\n");
}

// ASCIIコードと文字の一覧表示
void Sample4_2() {
	// 文字からASCIIコードの取得
	int from = 'A';
	int to = 'Z';
	// ASCIIコード上の大文字小文字間の差分を取得
	int offset = 'a' - 'A';

	// ループでコード・文字を出力する
	printf("Code: Char  Code: Char\n");
	for (int i = from; i < to; i++) {
		// iの値がそのままASCIIコードになる
		printf("%4d: %c   %6d: %c\n", i, i, i + offset, i + offset);
	}
	printf("\n");
}