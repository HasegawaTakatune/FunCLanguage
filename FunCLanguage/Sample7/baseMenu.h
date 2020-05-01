#pragma once
#include <vector>
#include <string>
#include "Item.h"

// 麺類、丼もの、カレーメニューのベースクラス
// このベースクラスを継承することで、大まかな処理の実装を省き
// 複数種類のクラスを作成します。
class baseMenu
{
public:
	// コンストラクタ
	baseMenu();
	// デストラクタ
	~baseMenu();

	// GetItems・GetNameはカプセル化のつもりで作成しています。
	// このベースクラス以外では変更しない前提なので、ベースクラス
	// 内で処理を完結させる。継承先でこの関数の記述はないものとします。
	// アイテム取得
	std::vector<Item> GetItems();
	// 名前取得
	std::string GetName();

protected:
	// メニュー項目の名前
	std::string name;
	// メニュー内の商品リスト
	std::vector<Item> items;

	// アイテム初期化（抽象関数）
	// 上書きされる前提で関数の枠だけを作成しています。
	// そのため、実際の処理に関しては記述しません。
	virtual void InitItems();

};

// コンストラクタ
baseMenu::baseMenu()
{
	InitItems();
}

// デストラクタ
baseMenu::~baseMenu()
{

}

// アイテム取得
inline std::vector<Item> baseMenu::GetItems()
{
	return items;
}

// 名前取得
inline std::string baseMenu::GetName()
{
	return name;
}

// アイテム初期化
// オーバーロード前提なので、内容は記述しない。
inline void baseMenu::InitItems()
{
}
