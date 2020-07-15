#pragma once
#include <string>

using namespace std;

static const string MARK_SPADE = "SPADE";		/// <summary>スペード</summary>
static const string MARK_CLUB = "CLUB";			/// <summary>クラブ</summary>
static const string MARK_DIAMOND = "DIAMOND";	/// <summary>ダイヤ</summary>
static const string MARK_HEART = "HEART";		/// <summary>ハート</summary>
static const string MARK_JOKER = "JOKER";		/// <summary>ジョーカー</summary>

/// <summary>カードクラス</summary>
class Card
{
public:

	static const int SPADE = 1;			/// <summary>スペード定数</summary>
	static const int CLUB = 2;			/// <summary>クラブ定数</summary>
	static const int DIAMOND = 3;		/// <summary>ダイヤ定数</summary>
	static const int HEART = 4;			/// <summary>ハート定数</summary>
	static const int JOKER = 5;			/// <summary>ジョーカー定数</summary>

	static const int NUMBER_MAX = 14;	/// <summary>カード数値の最大値</summary>
	static const int MARK_MAX = 5;		/// <summary>マーク定数の最大値</summary>

	/// <summary>コンストラクタ</summary>
	Card();
	/// <summary>コンストラクタ</summary>
	Card(int number, int mark);
	/// <summary>デストラクタ</summary>
	~Card();

	/// <summary>カード数値取得</summary>
	int GetNumber() { return number; }
	/// <summary>カードマーク取得（数値）</summary>
	int GetMark() { return mark; }
	/// <summary>カードマーク取得（文字）</summary>
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

	/// <summary>数値</summary>
	int number;
	/// <summary>マーク</summary>
	int mark;
};

/// <summary>コンストラクタ</summary>
Card::Card() {
	number = NUMBER_MAX;
	mark = MARK_MAX;
}

/// <summary>コンストラクタ</summary>
Card::Card(int number, int mark)
{
	if ((number < 1 || NUMBER_MAX <= number) || (mark < 0 || MARK_MAX <= mark))
	{
		this->number = NUMBER_MAX;
		this->mark = MARK_MAX;
		return;
	}

	this->number = number;
	this->mark = mark;
}

/// <summary>デストラクタ</summary>
Card::~Card()
{
}