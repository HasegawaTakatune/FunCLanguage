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

protected:
	// アイテム初期化
	void InitItems() override;

private:
	// 親クラス設定
	// 他の言語ではsuperやbaseという名前で親クラスを呼び出すことができる。
	// C++でははそれができないみたいなので、別途親クラスを宣言している。
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