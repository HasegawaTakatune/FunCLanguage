#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Card.h"

using namespace std;

/// <summary>�f�b�L�N���X</summary>
class Deck
{
public:

	/// <summary>�f�b�L�̃J�[�h�ő喇��</summary>
	static const int DECK_LENGTH = 52;

	/// <summary>�R���X�g���N�^</summary>
	Deck();
	/// <summary>�f�X�g���N�^</summary>
	~Deck();

	/// <summary>������</summary>
	void Init();
	/// <summary>�f�b�L�J�[�h��S�ĕ\��</summary>
	void ShowAll();
	/// <summary>�܂������Ă��Ȃ��f�b�L�J�[�h��\��</summary>
	void ShowAciveCard();
	/// <summary>�f�b�L���V���b�t������</summary>
	void Shuffle();
	/// <summary>�J�[�h���擾����</summary>
	Card GetCard();
	/// <summary>���̃J�[�h��ݒ肷��</summary>
	void Next();
	/// <summary>�J�[�h���Ō�܂ň����������m�F����</summary>
	bool GameSet();

private:

	/// <summary>�f�b�L</summary>
	vector<Card> deck = vector<Card>();
	/// <summary>�\���p�̃f�b�L</summary>
	int showDeck[DECK_LENGTH];
	/// <summary>�C���f�b�N�X</summary>
	int index = 0;
};

/// <summary>�R���X�g���N�^</summary>
Deck::Deck()
{
	int count = 0;
	index = 0;
	deck.clear();
	deck.reserve(DECK_LENGTH);

	for (int i = 1; i < Card::MARK_MAX; i++) {
		for (int j = 1; j < Card::NUMBER_MAX; j++) {
			deck.push_back(Card(j, i));
			showDeck[count] = j;
			count++;
		}
	}
}

/// <summary>�f�X�g���N�^</summary>
Deck::~Deck()
{
}

/// <summary>������</summary>
inline void Deck::Init()
{
	int count = 0;
	index = 0;
	deck.clear();
	deck.reserve(DECK_LENGTH);

	for (int i = 1; i < Card::MARK_MAX; i++) {
		for (int j = 1; j < Card::NUMBER_MAX; j++) {
			deck.push_back(Card(j, i));
			showDeck[count] = j;
			count++;
		}
	}
}

/// <summary>�f�b�L�J�[�h��S�ĕ\��</summary>
inline void Deck::ShowAll()
{
	for (int i = 0; i < deck.size(); i++) {
		cout << deck[i].GetMarkToString() << deck[i].GetNumber() << endl;
	}
}

/// <summary>�܂������Ă��Ȃ��f�b�L�J�[�h��\��</summary>
inline void Deck::ShowAciveCard()
{
	int count = 0;

	cout << "��������������������������������������������������������������������������������������������������" << endl;
	for (int i = 1; i < Card::MARK_MAX; i++) {

		switch (i)
		{
		case Card::SPADE: cout << left << setw(8) << MARK_SPADE; break;
		case Card::CLUB:cout << left << setw(8) << MARK_CLUB; break;
		case Card::DIAMOND:cout << left << setw(8) << MARK_DIAMOND; break;
		case Card::HEART:cout << left << setw(8) << MARK_HEART; break;
		default:break;
		}

		for (int j = 1; j < Card::NUMBER_MAX; j++) {
			if (showDeck[count] != 0)
				cout << left << setw(3) << showDeck[count];
			else
				cout << left << setw(3) << " ";
			count++;
		}
		cout << endl;
	}
	cout << "��������������������������������������������������������������������������������������������������" << endl;
}

/// <summary>�f�b�L���V���b�t������</summary>
inline void Deck::Shuffle()
{
	random_device rand;
	mt19937 engine(rand());

	shuffle(deck.begin(), deck.end(), engine);
}

/// <summary>�J�[�h���擾����</summary>
inline Card Deck::GetCard()
{
	return deck[index];
}

/// <summary>���̃J�[�h��ݒ肷��</summary>
inline void Deck::Next()
{
	Card card = deck[index];
	int mark = card.GetMark();
	int number = card.GetNumber();

	showDeck[((mark - 1) * 13) + number - 1] = 0;

	index++;
}

/// <summary>�J�[�h���Ō�܂ň����������m�F����</summary>
inline bool Deck::GameSet()
{
	return ((DECK_LENGTH - 1) <= index);
}
