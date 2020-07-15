#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Card.h"

using namespace std;

/// <summary>デッキクラス</summary>
class Deck
{
public:

	/// <summary>デッキのカード最大枚数</summary>
	static const int DECK_LENGTH = 52;

	/// <summary>コンストラクタ</summary>
	Deck();
	/// <summary>デストラクタ</summary>
	~Deck();

	/// <summary>初期化</summary>
	void Init();
	/// <summary>デッキカードを全て表示</summary>
	void ShowAll();
	/// <summary>まだ引いていないデッキカードを表示</summary>
	void ShowAciveCard();
	/// <summary>デッキをシャッフルする</summary>
	void Shuffle();
	/// <summary>カードを取得する</summary>
	Card GetCard();
	/// <summary>次のカードを設定する</summary>
	void Next();
	/// <summary>カードが最後まで引いたかを確認する</summary>
	bool GameSet();

private:

	/// <summary>デッキ</summary>
	vector<Card> deck = vector<Card>();
	/// <summary>表示用のデッキ</summary>
	int showDeck[DECK_LENGTH];
	/// <summary>インデックス</summary>
	int index = 0;
};

/// <summary>コンストラクタ</summary>
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

/// <summary>デストラクタ</summary>
Deck::~Deck()
{
}

/// <summary>初期化</summary>
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

/// <summary>デッキカードを全て表示</summary>
inline void Deck::ShowAll()
{
	for (int i = 0; i < deck.size(); i++) {
		cout << deck[i].GetMarkToString() << deck[i].GetNumber() << endl;
	}
}

/// <summary>まだ引いていないデッキカードを表示</summary>
inline void Deck::ShowAciveCard()
{
	int count = 0;

	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
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
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
}

/// <summary>デッキをシャッフルする</summary>
inline void Deck::Shuffle()
{
	random_device rand;
	mt19937 engine(rand());

	shuffle(deck.begin(), deck.end(), engine);
}

/// <summary>カードを取得する</summary>
inline Card Deck::GetCard()
{
	return deck[index];
}

/// <summary>次のカードを設定する</summary>
inline void Deck::Next()
{
	Card card = deck[index];
	int mark = card.GetMark();
	int number = card.GetNumber();

	showDeck[((mark - 1) * 13) + number - 1] = 0;

	index++;
}

/// <summary>カードが最後まで引いたかを確認する</summary>
inline bool Deck::GameSet()
{
	return ((DECK_LENGTH - 1) <= index);
}
