#pragma once
#include <string>

using namespace std;

static const string MARK_SPADE = "SPADE";
static const string MARK_CLUB = "CLUB";
static const string MARK_DIAMOND = "DIAMOND";
static const string MARK_HEART = "HEART";
static const string MARK_JOKER = "JOKER";

class Card
{
public:
	static const int SPADE = 1;
	static const int CLUB = 2;
	static const int DIAMOND = 3;
	static const int HEART = 4;
	static const int JOKER = 5;

	static const int NUMBER_MAX = 14;
	static const int MARK_MAX = 5;

	Card();
	Card(int number, int mark);
	~Card();	

	int GetNumber() { return number; }
	int GetMark() { return mark; }
	string GetMarkToString() {
		switch (mark)
		{
		case SPADE:return MARK_SPADE; break;
		case CLUB:return MARK_CLUB; break;
		case DIAMOND:return MARK_DIAMOND; break;
		case HEART:return MARK_HEART; break;
		case JOKER:return MARK_JOKER; break;
		default:return"NONE"; break;
		};
	}

private:
	int number;
	int mark;
};

Card::Card() {
	number = NUMBER_MAX;
	mark = MARK_MAX;
}

Card::Card(int number, int mark)
{
	if ((number < 1 || NUMBER_MAX <= number) || (mark < 0 || MARK_MAX <= mark))
	{
		this->number = 0;
		this->mark = 0;
		return;
	}

	this->number = number;
	this->mark = mark;
}

Card::~Card()
{
}