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