#pragma once
#include "baseMenu.h"

// 丼もの
class Bowl : public baseMenu
{
public:
	// コンストラクタ
	Bowl();
	// デストラクタ
	~Bowl();

	// アイテム初期化
	void InitItems() override;

private:
	// 親クラス設定
	typedef baseMenu super;
};

// コンストラクタ
Bowl::Bowl()
{
	name = "丼物";
	InitItems();
}

// デストラクタ
Bowl::~Bowl()
{
}

// アイテム初期化
void Bowl::InitItems()
{
	// 丼ものの項目を追加していく
	super::items.push_back(Item("牛丼", 550));
	super::items.push_back(Item("豚丼", 450));
	super::items.push_back(Item("天かす丼", 350));
	super::items.push_back(Item("うな丼", 800));
}