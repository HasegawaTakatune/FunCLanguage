#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Card.h"

using namespace std;

class Deck
{
public:

	static const int DECK_LENGTH = 52;

	Deck();
	~Deck();

	void Init();
	void ShowAll();
	void ShowAciveCard();
	void Shuffle();
	Card GetCard();
	void Next();
	bool GameSet();

private:

	vector<Card> deck = vector<Card>();
	int showDeck[DECK_LENGTH];
	int index = 0;
};

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

Deck::~Deck()
{
}

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

inline void Deck::ShowAll()
{
	for (int i = 0; i < deck.size(); i++) {
		cout << deck[i].GetMarkToString() << deck[i].GetNumber() << endl;
	}
}

inline void Deck::ShowAciveCard()
{
	int count = 0;

	cout << "„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª" << endl;
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
	cout << "„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª„ª" << endl;
}

inline void Deck::Shuffle()
{
	random_device rand;
	mt19937 engine(rand());

	shuffle(deck.begin(), deck.end(), engine);
}

inline Card Deck::GetCard()
{
	return deck[index];
}

inline void Deck::Next()
{
	Card card = deck[index];
	int mark = card.GetMark();
	int number = card.GetNumber();

	showDeck[((mark - 1) * 13) + number - 1] = 0;

	index++;
}

inline bool Deck::GameSet()
{
	return ((DECK_LENGTH - 1) <= index);
}
