#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Sample6_1();
void Operation_System();

// 6・・・ビット演算のサンプル
int main()
{
	Sample6_1();
	
	// おまけ
	//Operation_System();
	return 0;
}

// ビット列の出力
void ShowBinary(char value)
{
	int len = 8;
	int bit[8];
	int x;

	for (int i = 0; i < len; i++)
	{
		x = 1 << i;
		x = value & x;
		bit[len - i - 1] = x >> i;
	}

	printf("0b");
	for (int i = 0; i < len; i++)
	{
		printf("%d", bit[i]);
	}
}

// 結果出力
void ShowResult(char result)
{
	printf("10進数：%-4d　　2進数：", result);
	ShowBinary(result);
	printf("\n");
}

// ビット演算出力
void Sample6_1()
{
	char value1 = 0b00000101;
	char value2 = 0b00001111;
	char result;

	// 計算対象を出力
	ShowResult(value1);
	ShowResult(value2);
	printf("\n");

	// 論理積
	printf("%-12s%-5s", "論理積", "(&)");
	result = value1 & value2;
	ShowResult(result);

	// 論理和
	printf("%-12s%-5s", "論理和", "(|)");
	result = value1 | value2;
	ShowResult(result);

	// 否定
	printf("%-12s%-5s", "否定", "(~)");
	result = ~value1;
	ShowResult(result);

	// 排他的論理和
	printf("%-12s%-5s", "排他的論理和", "(^)");
	result = value1 ^ value2;
	ShowResult(result);

	// 左シフト
	printf("%-12s%-5s", "左シフト", "(<<)");
	result = value1 << 1;
	ShowResult(result);

	// 右シフト
	printf("%-12s%-5s", "右シフト", "(>>)");
	result = value1 >> 1;
	ShowResult(result);

	printf("\n");

	// 負の右シフト
	char value3 = 0b11100110;
	ShowResult(value3);
	printf("%-12s%-5s", "負の右シフト", "(>>)");
	result = value3 >> 1;
	ShowResult(result);

	printf("\n");
}

//■┳□┳■┳□┳■┳□┳■┳□┳■┳□
//┣　下記ソースはおまけです。　　　　┫
//□┻■┻□┻■┻□┻■┻□┻■┻□┻■
//

// 武器配列の長さ
const int WEAPON_LENGTH = 8;
// 操作配列の長さ
const int OPERATION_LENGTH = 4;
// 武器名リスト
const char* WeaponName[WEAPON_LENGTH] = { "SVTT_1","SVTT_2","SVTT_3","SVTT_4","SVTT_5","SVTT_6","Mk.45_1","Mk.45_2" };
// 操作名リスト
const char* Operation[OPERATION_LENGTH] = { "Loading","Main gun firing!!","Torpedo launch!!","Full fire!!" };

// 武器ステータスの出力
void ShowWeaponsState(char value)
{
	// ステータス：グリーン
	const int GREEN = 1;

	// ビット列の長さ
	int len = 8;
	// ビット配列
	int bit[8];
	// 一時保存
	int buff;

	for (int i = 0; i < len; i++)
	{
		// i番目を0/1を判定し、ビット配列に格納
		buff = 1 << i;
		buff = value & buff;
		bit[len - i - 1] = buff >> i;
	}

	for (int i = 0; i < len; i++)
	{
		// ビット配列の値が1の場合「Loaded」・0の場合「Injection」を出力
		if (bit[i] == GREEN)
		{
			printf("\x1b[42m"); // 背景色：緑
			printf("%-15s", "Loaded");
		}
		else
		{
			printf("\x1b[41m"); // 背景色：赤
			printf("%-15s", "Injection");
		}
		printf("%s\n", WeaponName[i]);
	}
	printf("\n\n");
	printf("\x1b[49m"); // 背景色：デフォルト
}

// ローディング処理
void Loading()
{
	// 待ち時間（0.2秒）
	const float WAIT_TIME = 0.2 * 1000;
	// 待ちカウント
	int waitCount = rand() % 5 + 1;
	// カウント
	int count = 0;

	system("cls");
	// 「Loading...」を出力
	while (count < waitCount)
	{
		printf("Loading");
		Sleep(WAIT_TIME);
		printf(".");
		Sleep(WAIT_TIME);
		printf(".");
		Sleep(WAIT_TIME);
		printf(".");
		Sleep(WAIT_TIME);
		system("cls");
		count++;
	}
}

// 戦術システム‼
void Operation_System()
{
	// あたご型護衛艦
	// https://ja.wikipedia.org/wiki/%E3%81%82%E3%81%9F%E3%81%94%E5%9E%8B%E8%AD%B7%E8%A1%9B%E8%89%A6

	// Mk.32 魚雷発射管 Mark 32  Surface Vessel Torpedo Tubes
	// https://ja.wikipedia.org/wiki/Mk_32_%E7%9F%AD%E9%AD%9A%E9%9B%B7%E7%99%BA%E5%B0%84%E7%AE%A1
	const char SVTT_1 = 0b10000000;
	const char SVTT_2 = 0b01000000;
	const char SVTT_3 = 0b00100000;
	const char SVTT_4 = 0b00010000;
	const char SVTT_5 = 0b00001000;
	const char SVTT_6 = 0b00000100;
	// 魚雷
	const char TORPEDO = 0b11111100;

	// Mk.45 5インチ砲
	// https://ja.wikipedia.org/wiki/Mk_45_5%E3%82%A4%E3%83%B3%E3%83%81%E7%A0%B2
	const char MK45_1 = 0b00000010;
	const char MK45_2 = 0b00000001;
	// 主砲
	const char MAIN_GUN = 0b00000011;
	// ブランク
	const char BLANK = 0b00000000;
	// 武器ステータス
	char weapons = 0b11111111;
	// 命令保持
	char order = 0b00000000;

	// ループ判定
	bool isLoop = true;
	// 選択肢の保持
	int sel;

	// 起動判定
	printf("Start up...\nYes:1/No:other\n");
	scanf_s("%d", &sel);
	if (sel != 1)return;

	// ローディング
	Loading();

	// 戦術システム本編
	while (isLoop) {
		// ステータス出力
		ShowWeaponsState(weapons);

		// 武器名出力
		for (int i = 0; i < WEAPON_LENGTH; i++) {
			printf("%-3d:%-10s\n", i, WeaponName[i]);
		}
		// 操作名出力
		for (int i = 0; i < OPERATION_LENGTH; i++)
		{
			printf("%-3d:%-10s\n", WEAPON_LENGTH + i, Operation[i]);
		}
		printf("%-3d:exit", WEAPON_LENGTH + OPERATION_LENGTH);
		printf("Please Enter your Choice ? \n");

		// 入力
		scanf_s("%d", &sel);

		// 入力ごとの処理
		// 0～7 魚雷・主砲の装填設定
		// 8	装填
		// 9	主砲発射
		// 10	魚雷発射
		// 11	一斉清掃
		// 12	終了
		switch (sel)
		{
		case 0:order = order | SVTT_1; printf("%-10s SET", WeaponName[0]); break;
		case 1:order = order | SVTT_2; printf("%-10s SET", WeaponName[1]); break;
		case 2:order = order | SVTT_3; printf("%-10s SET", WeaponName[2]); break;
		case 3:order = order | SVTT_4; printf("%-10s SET", WeaponName[3]); break;
		case 4:order = order | SVTT_5; printf("%-10s SET", WeaponName[4]); break;
		case 5:order = order | SVTT_6; printf("%-10s SET", WeaponName[5]); break;
		case 6:order = order | MK45_1; printf("%-10s SET", WeaponName[6]); break;
		case 7:order = order | MK45_2; printf("%-10s SET", WeaponName[7]); break;
		case 8:weapons = weapons | order; order = BLANK; printf("Execution >> %s", Operation[0]); break;
		case 9:weapons = weapons ^ MAIN_GUN; printf("Execution >> %s", Operation[1]); break;
		case 10:weapons = weapons ^ TORPEDO; printf("Execution >> %s", Operation[2]); break;
		case 11:weapons = BLANK; printf("Execution >> %s", Operation[3]); break;
		case 12:isLoop = false; break;
		default:printf("No choice!!"); break;
		}
		printf("\n");
		system("pause");
		system("cls");
	}
	printf("END");
}