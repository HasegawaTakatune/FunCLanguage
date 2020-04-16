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

	// �A�C�e��������
	void InitItems() override;

private:
	// �e�N���X�ݒ�
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