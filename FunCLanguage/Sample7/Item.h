#pragma once
#include <string>

// �A�C�e��
class Item
{
public:
	// �R���X�g���N�^
	Item();
	// �R���X�g���N�^
	Item(std::string, int);
	// �f�X�g���N�^
	~Item();

	// ���O�擾
	std::string GetName();
	// �l�i�擾
	int GetPrice();

private:
	// ���O
	std::string name;
	// �l�i
	int price;
};

// �R���X�g���N�^
Item::Item()
{
	name = "����";
	price = 0;
}

// �R���X�g���N�^
Item::Item(std::string name, int price) {
	this->name = name;
	this->price = price;
}

// �f�X�g���N�^
Item::~Item()
{
}

// ���O�擾
inline std::string Item::GetName()
{
	return name;
}

// �l�i�擾
inline int Item::GetPrice()
{
	return price;
}
