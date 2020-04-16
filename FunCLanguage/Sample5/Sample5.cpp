#include <stdio.h>

void Sample5_1();
void Sample5_2();
void Sample5_3();
void Sample5_4();
void Sample5_5();
void Sample5_6();

// 5・・・ポインタのサンプル
int main()
{
	Sample5_1();
	Sample5_2();
	Sample5_3();
	Sample5_4();
	Sample5_5();
	Sample5_6();
	return 0;
}

// 変数の値・アドレスとポインタの参照値・格納アドレスを出力する
void Sample5_1()
{
	int value = 1;
	int* pointer = &value;

	// 変数の値・アドレスを出力する
	printf("valueの値　　　　：%d\n", value);
	printf("valueのアドレス　：%p\n", &value);

	printf("\n");

	// ポインタの参照先の値・格納したアドレスを出力する
	printf("pointerの値　　　：%d\n", *pointer);
	printf("pointerのアドレス：%p\n", pointer);

	printf("\n");
}

// 値渡しされた値を加算する
void Increment(int result) { result++; }
// 参照渡しされたアドレスの値を加算する
void Increment(int* result) { *result = *result + 1; }
// 値渡し・参照渡しの関数呼び出しを行う
void Sample5_2()
{
	int result = 1;
	printf("加算前：%d\n", result);

	// 値渡しをしてもresult変数の値は変わらない
	Increment(result);
	printf("加算後：%d\n", result);

	// 参照渡しをするとresult変数の値は変わる
	Increment(&result);
	printf("加算後：%d\n", result);

	printf("\n");
}

// アドレスの指す値を出力し、アドレスを+1スライドさせていくのをlength分繰り返す
void ShowItems(int* pointer, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("No.%-2d  Value %d\n", i + 1, *pointer);
		pointer++;
	}
}
// 配列の参照渡し
void Sample5_3() {
	const int SIZE = 10;
	int items[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };

	// 配列の先頭アドレスを渡す
	ShowItems(&items[0], SIZE);

	printf("\n");
}

// 足し算
int Sum(int value1, int value2) { return value1 + value2; }
// 掛け算
int Mul(int value1, int value2) { return value1 * value2; }
// 関数ポインタ
void Sample5_4() {
	int value1 = 12;
	int value2 = 13;
	int result = 0;

	// 関数ポインタの宣言 typedef 戻り値 (*変数名)(引数);で宣言する
	typedef int (*Calc)(int value1, int value2);
	Calc calc;

	// 足し算関数のポインタを渡して実行する
	calc = &Sum;
	result = calc(value1, value2);
	printf("%d + %d = %d\n", value1, value2, result);

	// 掛け算関数のポインタを渡して実行する
	calc = &Mul;
	result = calc(value1, value2);
	printf("%d x %d = %d\n", value1, value2, result);

	printf("\n");
}

// キャラクタ構造体
typedef struct
{
	char* name;
	int age;
}CHARACTER;
// 長さ
const int LENGTH = 4;
// サイズ
const int SIZE = 10;
// キャラクタを出力する
void ShowListStatus(CHARACTER* pointer)
{
	for (int i = 0; i < LENGTH; i++)
	{
		printf("Name: %-10s  Age:%-10d\n", pointer->name, pointer->age);
		pointer++;
	}
}
// 構造体の参照渡し
void Sample5_5()
{
	// 構造体に格納するデータ
	char name[LENGTH][SIZE] = { "Tom","Rock","Alisa","Merry" };
	int age[LENGTH] = { 16,23,15,19 };

	// キャラクタ構造体の宣言
	CHARACTER status;
	CHARACTER charaList[SIZE];

	// データ格納
	for (int i = 0; i < LENGTH; i++)
	{
		charaList[i].name = name[i];
		charaList[i].age = age[i];
	}

	// キャラクタ構造体の出力
	ShowListStatus(&charaList[0]);

	printf("\n");
}

// ポインタのポインタ
void Sample5_6()
{
	// 変数
	int value = 456;
	// 変数のポインタ
	int* pointer = &value;
	// 変数のポインタのポインタ
	int** ppointer = &pointer;

	printf("valueの値：%d　アドレス：%p\n", value, &value);
	printf("pointerのアドレス：%p\n", pointer);
	printf("ppointerのアドレス：%p\n", ppointer);
	printf("\n");
}