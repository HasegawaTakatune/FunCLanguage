#pragma once
#include "baseMenu.h"

// ������
class Bowl : public baseMenu
{
public:
	// �R���X�g���N�^
	Bowl();
	// �f�X�g���N�^
	~Bowl();

protected:
	// �A�C�e��������
	void InitItems() override;

private:
	// �e�N���X�ݒ�
	// ���̌���ł�super��base�Ƃ������O�Őe�N���X���Ăяo�����Ƃ��ł���B
	// C++�ł͂͂��ꂪ�ł��Ȃ��݂����Ȃ̂ŁA�ʓr�e�N���X��錾���Ă���B
	typedef baseMenu super;
};

// �R���X�g���N�^
Bowl::Bowl()
{
	name = "����";
	InitItems();
}

// �f�X�g���N�^
Bowl::~Bowl()
{
}

// �A�C�e��������
void Bowl::InitItems()
{
	// �����̂̍��ڂ�ǉ����Ă���
	super::items.push_back(Item("����", 550));
	super::items.push_back(Item("�ؘ�", 450));
	super::items.push_back(Item("�V������", 350));
	super::items.push_back(Item("���Ș�", 800));
}