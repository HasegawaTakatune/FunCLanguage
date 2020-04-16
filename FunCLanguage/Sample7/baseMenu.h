#pragma once
#include <vector>
#include <string>
#include "Item.h"

// 麺類、丼もの、カレーメニューのベースクラス
class baseMenu
{
public:
	// コンストラクタ
	baseMenu();
	// デストラクタ
	~baseMenu();

	// アイテム取得
	std::vector<Item> GetItems();
	// 名前取得
	std::string GetName();
	// アイテム初期化
	virtual void InitItems();

protected:
	// メニュー項目の名前
	std::string name;
	// メニュー内の商品リスト
	std::vector<Item> items;
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
