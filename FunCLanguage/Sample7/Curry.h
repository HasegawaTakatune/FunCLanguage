#pragma once
#include "baseMenu.h";

// カレー
class Curry : public baseMenu
{
public:
	// コンストラクタ
	Curry();
	// デストラクタ
	~Curry();

	// アイテム初期化
	void InitItems() override;

private:
	// 親クラス設定
	typedef baseMenu super;
};

// コンストラクタ
Curry::Curry()
{
	name = "カレー";
	InitItems();
}

// デストラクタ
Curry::~Curry()
{
}

// アイテム初期化
void Curry::InitItems()
{
	// カレーの項目を追加していく
	super::items.push_back(Item("カレー", 550));
	super::items.push_back(Item("チキンカレー", 400));
	super::items.push_back(Item("ポークカレー", 450));
	super::items.push_back(Item("バターカレー", 600));
	super::items.push_back(Item("グリーンカレー", 800));
}