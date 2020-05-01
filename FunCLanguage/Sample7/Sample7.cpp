#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Noodles.h"
#include "Bowl.h"
#include "Curry.h"

using namespace std;

// 7・・・オブジェクト指向（クラス）のサンプル
int main()
{
	const int MENU = 0;		// メニュー
	const int ITEM = 1;		// アイテム
	const int RETURN = 98;	// 戻る
	const int ORDER = 99;	// 注文

	const int YES = 1;		// Yes

	// メニュー一覧
	// ベースクラスが同じだと、別々のクラスを一括してリストに格納できる。
	// 関数も同じように呼び出すことができます。今回ではGetNameやGetItemsを指します。
	std::vector<baseMenu> menu;
	menu.push_back(Noodles());	// 麺類追加
	menu.push_back(Bowl());		// 丼もの追加
	menu.push_back(Curry());	// カラー追加

	// コンテンツ（メニュー・アイテムを切り替える）
	int content = 0;
	// 入力の一時保存
	int sel = 0;
	// メニュー選択
	int selMenu = 0;

	// アイテムリスト
	std::vector<Item> items;
	// 選択したアイテムリスト
	std::vector<Item> selItems;

	// メインループ
	while (true)
	{
		switch (content)
		{
		case MENU: // メニュー一覧出力
			for (int i = 0; i < menu.size(); i++)
				std::cout << std::left << std::setw(2) << i << "." << menu[i].GetName() << endl;
			break;

		case ITEM: // 商品一覧出力
			items = menu[selMenu].GetItems();
			for (int i = 0; i < items.size(); i++)
				std::cout << std::left << std::setw(2) << i << "." << items[i].GetName() << endl;
			break;

		default:
			break;
		}
		
		std::cout << RETURN << ".戻る" << endl;
		std::cout << ORDER << ".注文" << endl;

		std::cin >> sel;	// 入力
		std::system("cls");	// 画面クリア

		// メニュー一覧に戻る
		if (sel == RETURN)content = MENU;
		// 注文の確定
		if (sel == ORDER)
		{
			// 合計金額の格納
			int total = 0;

			// 注文内容を一覧出力
			std::cout << std::left << std::setw(20) << "品名" << ":" << std::right << std::setw(10) << "値段" << endl;
			for (int i = 0; i < selItems.size(); i++) {
				std::cout << std::left << std::setw(20) << selItems[i].GetName() << ":" << std::right << std::setw(10) << selItems[i].GetPrice() << endl;

				// 合計金額を加算
				total += selItems[i].GetPrice();
			}

			// 支払い確認
			std::cout << "お支払い額：" << total << endl;
			std::cout << "お支払いしますか？　1.はい　0.いいえ" << endl;

			std::cin >> sel;	// 入力
			std::system("cls");	// 画面クリア

			if (sel == YES)
				std::cout << "注文が確定しました。" << endl;		// 注文確定
			else
				std::cout << "注文をキャンセルしました。" << endl;	// 注文キャンセル

			std::system("pause");	// ボタン入力待ち
			break;
		}

		switch (content)
		{
		case MENU:	// メニュー選択
			if (0 <= sel && sel < menu.size())
			{
				// 商品一覧出力に遷移
				selMenu = sel;
				content = ITEM;
			}
			break;

		case ITEM:	// 商品一覧
			items = menu[selMenu].GetItems();
			if (0 <= sel && sel < items.size())
			{
				// 選択した商品を一時保存しメニュー選択に遷移する
				content = MENU;
				selItems.push_back(items[sel]);
			}
			break;

		default: break;
		}
	}
	std::system("cls");	// 画面クリア
	std::cout << "END" << endl;
	return 0;
}