#pragma once
#include <string>

// アイテム
class Item
{
public:
	// コンストラクタ
	Item();
	// コンストラクタ
	Item(std::string, int);
	// デストラクタ
	~Item();

	// 名前取得
	std::string GetName();
	// 値段取得
	int GetPrice();

private:
	// 名前
	std::string name;
	// 値段
	int price;
};

// コンストラクタ
Item::Item()
{
	name = "未定";
	price = 0;
}

// コンストラクタ
Item::Item(std::string name, int price) {
	this->name = name;
	this->price = price;
}

// デストラクタ
Item::~Item()
{
}

// 名前取得
inline std::string Item::GetName()
{
	return name;
}

// 値段取得
inline int Item::GetPrice()
{
	return price;
}
