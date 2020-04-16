#include <stdio.h>
#include <string.h>

void Sample3_1();
void Sample3_2();
void Sample3_3();
void Sample3_4();
void Sample3_5();

// 3・・・char型についてのサンプル
int main()
{
	Sample3_1();
	Sample3_2();
	Sample3_3();
	Sample3_4();
	Sample3_5();

	return 0;
}

// 配列を使った文字列
void Sample3_1()
{
	// 配列サイズを指定した宣言方法
	char str1[256] = "Hello";
	// 文字列から配列のサイズを決める宣言方法
	char str2[] = "Hello";

	printf("%s\n", str1);

	// 文字配列のサイズ分ループして出力する。文字列には終端文字「\0」も含まれるため
	// 最後に空白が出力される。
	for (int i = 0; i < sizeof(str2); i++) {
		printf("len %d: %c\n", i + 1, str2[i]);
	}

	printf("\n");
}

// ポインタを使った文字列
void Sample3_2()
{
	// char型のポインタに文字列を格納する
	const char* pntr = "Hello";

	printf("%s\n", pntr);

	// 文字列の長さ分ループして出力する。文字列の長さなので終端文字「\0」は含まれない
	// ポインタの場合でも終端文字「\0」は入っている
	for (int i = 0; i < strlen(pntr); i++) {
		printf("len %d: %c\n", i + 1, pntr[i]);
	}

	printf("\n");
}

// 文字列のコピー
void Sample3_3()
{
	const int SIZE = 16;
	char str1[SIZE] = "Hello World!";
	char str2[SIZE], str3[SIZE];

	// str1の内容をstr2にコピーする
	strcpy_s(str2, str1);
	printf("str2: %s\n", str2);

	// str1の先頭から5文字分をstr3にコピーする
	strncpy_s(str3, str1, 5);
	printf("str3: %s\n", str3);
	printf("\n");
}

// 文字列の連結
void Sample3_4()
{
	const int SIZE = 16;
	const char str1[] = "Hello";
	const char str2[] = "World!";
	// 連結先の文字配列のサイズより連結する文字列のサイズが大きいと
	// 必要とされるメモリが確保できずにエラーが起きる
	char str3[SIZE] = "";

	// str3にstr1・str2の文字列を連結する（sizeofでstr3のサイズ指定をする）
	strcat_s(str3, sizeof(str3), str1);
	strcat_s(str3, sizeof(str3), str2);

	printf("str3: %s\n", str3);
	printf("\n");
}

// 文字列の比較
void Sample3_5()
{
	const int SIZE = 16;
	char str1[SIZE] = "Hello World!";
	char str2[SIZE] = "Hello World!";
	char str3[SIZE] = "Hello";

	// そのまま比較をするとアドレスの比較をしてしまう
	if (str1 == str2)
		printf("%s(str1)と%s(str2)は同じ文字列です。\n", str1, str2);
	else
		printf("%s(str1)と%s(str2)は違う文字列です。\n", str1, str2);

	// str1とstr2の文字列を比較
	if (strcmp(str1, str2) == 0)
		printf("%s(str1)と%s(str2)は同じ文字列です。\n", str1, str2);
	else
		printf("%s(str1)と%s(str2)は違う文字列です。\n", str1, str2);

	// str1とstr3の文字列を比較
	if (strcmp(str1, str3) == 0)
		printf("%s(str1)と%s(str3)は同じ文字列です。\n", str1, str3);
	else
		printf("%s(str1)と%s(str3)は違う文字列です。\n", str1, str3);
	printf("\n");
}