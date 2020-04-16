#pragma once
#include <vector>
#include <string>
#include "Item.h"

// �˗ށA�����́A�J���[���j���[�̃x�[�X�N���X
class baseMenu
{
public:
	// �R���X�g���N�^
	baseMenu();
	// �f�X�g���N�^
	~baseMenu();

	// �A�C�e���擾
	std::vector<Item> GetItems();
	// ���O�擾
	std::string GetName();
	// �A�C�e��������
	virtual void InitItems();

protected:
	// ���j���[���ڂ̖��O
	std::string name;
	// ���j���[���̏��i���X�g
	std::vector<Item> items;
};

// �R���X�g���N�^
baseMenu::baseMenu()
{
	InitItems();
}

// �f�X�g���N�^
baseMenu::~baseMenu()
{

}

// �A�C�e���擾
inline std::vector<Item> baseMenu::GetItems()
{
	return items;
}

// ���O�擾
inline std::string baseMenu::GetName()
{
	return name;
}

// �A�C�e��������
// �I�[�o�[���[�h�O��Ȃ̂ŁA���e�͋L�q���Ȃ��B
inline void baseMenu::InitItems()
{
}
