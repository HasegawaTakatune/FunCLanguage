#pragma once
#include "baseMenu.h"

// 麺類
class Noodles :public baseMenu
{
public:
	// コンストラクタ
	Noodles();
	// デストラクタ
	~Noodles();

	// アイテム初期化
	void InitItems() override;

private:
	// 親クラス設定
	typedef baseMenu super;
};

// コンストラクタ
Noodles::Noodles()
{
	name = "麺類";
	InitItems();
}

// デストラクタ
Noodles::~Noodles()
{
}

// アイテム初期化
void Noodles::InitItems()
{
	// 麺類の項目を追加していく
	super::items.push_back(Item("醤油ラーメン", 600));
	super::items.push_back(Item("塩ラーメン", 650));
	super::items.push_back(Item("豚骨ラーメン", 800));
	super::items.push_back(Item("チャーシューメン", 950));
}