#pragma once
#include "baseMenu.h";

// �J���[
class Curry : public baseMenu
{
public:
	// �R���X�g���N�^
	Curry();
	// �f�X�g���N�^
	~Curry();

	// �A�C�e��������
	void InitItems() override;

private:
	// �e�N���X�ݒ�
	typedef baseMenu super;
};

// �R���X�g���N�^
Curry::Curry()
{
	name = "�J���[";
	InitItems();
}

// �f�X�g���N�^
Curry::~Curry()
{
}

// �A�C�e��������
void Curry::InitItems()
{
	// �J���[�̍��ڂ�ǉ����Ă���
	super::items.push_back(Item("�J���[", 550));
	super::items.push_back(Item("�`�L���J���[", 400));
	super::items.push_back(Item("�|�[�N�J���[", 450));
	super::items.push_back(Item("�o�^�[�J���[", 600));
	super::items.push_back(Item("�O���[���J���[", 800));
}