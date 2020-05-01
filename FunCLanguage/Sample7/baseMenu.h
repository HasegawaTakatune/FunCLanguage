#pragma once
#include <vector>
#include <string>
#include "Item.h"

// �˗ށA�����́A�J���[���j���[�̃x�[�X�N���X
// ���̃x�[�X�N���X���p�����邱�ƂŁA��܂��ȏ����̎������Ȃ�
// ������ނ̃N���X���쐬���܂��B
class baseMenu
{
public:
	// �R���X�g���N�^
	baseMenu();
	// �f�X�g���N�^
	~baseMenu();

	// GetItems�EGetName�̓J�v�Z�����̂���ō쐬���Ă��܂��B
	// ���̃x�[�X�N���X�ȊO�ł͕ύX���Ȃ��O��Ȃ̂ŁA�x�[�X�N���X
	// ���ŏ���������������B�p����ł��̊֐��̋L�q�͂Ȃ����̂Ƃ��܂��B
	// �A�C�e���擾
	std::vector<Item> GetItems();
	// ���O�擾
	std::string GetName();

protected:
	// ���j���[���ڂ̖��O
	std::string name;
	// ���j���[���̏��i���X�g
	std::vector<Item> items;

	// �A�C�e���������i���ۊ֐��j
	// �㏑�������O��Ŋ֐��̘g�������쐬���Ă��܂��B
	// ���̂��߁A���ۂ̏����Ɋւ��Ă͋L�q���܂���B
	virtual void InitItems();

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
