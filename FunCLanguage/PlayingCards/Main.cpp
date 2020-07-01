#include <iostream>
#include <iomanip>
#include <regex>
#include <Windows.h>

#include "Deck.h"


#pragma region MainLoop
class GameManager
{
private:
	bool debugMode = true;
	int state = MENU;
	int score = 0;
	Deck deck = Deck(false);
	Card nowCard = Card();
	Card drawCard = Card();

public:
	static const int MENU = 0;
	static const int PLAY = 1;
	static const int END = 2;
	static const int EXIT = 3;

	static const int NONE = 0;
	static const int HIGH = 1;
	static const int LOW = 2;

	const string MenuInfo =
		"━━━━　High & Low　━━━━　\n"
		"ルール\n"
		"コンソール上に表示された数よりデッキから引いた数が\n"
		"高いか低いかを当てるゲームです。\n"
		"数が同じの場合は高いと判定されます。\n"
		"高いと思った場合：High（ h ）\n"
		"低いと思った場合：Low （ l ）\n"
		"を入力してください。\n"
		"\n\n\n"
		"ゲームを始めますか？\n"
		"Yes（ y ）：はじめる\n"
		"No （ n ）：おわる\n";

	GameManager();
	~GameManager();

	void MainLoop();
	void ShowMenu();
	void PlayGame();
	void GameEnd();
	bool CheckCommand(string command, string check, string check2 = "");
};

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::MainLoop()
{
	while (state != EXIT)
	{
		switch (state)
		{
		case MENU:ShowMenu(); break;
		case PLAY:PlayGame(); break;
		case END:GameEnd(); break;
		default:break;
		}
	}
}

void GameManager::ShowMenu()
{
	std::system("cls");

	deck.Init();
	deck.Shuffle();
	score = 0;
	nowCard = deck.GetCard();
	deck.Next();

	cout << MenuInfo << endl;

	string command;
	cin >> command;

	if (CheckCommand(command, "yes", "y"))state = PLAY;
	if (CheckCommand(command, "no", "n") || CheckCommand(command, "exit", "e"))state = EXIT;
}

void GameManager::PlayGame()
{
	std::system("cls");

	deck.ShowAciveCard();
	drawCard = deck.GetCard();

	cout << "<< SCORE  " << right << setw(15) << score * 100 << "  >>" << endl << endl << endl;

	if (debugMode)cout << "Next -->" << left << setw(9) << drawCard.GetMarkToString() << left << setw(2) << drawCard.GetNumber() << endl;

	cout << left << setw(9) << nowCard.GetMarkToString() << left << setw(2) << nowCard.GetNumber() << endl;
	cout << "high( h ) /  Low( l )" << endl;

	string command;
	cin >> command;

	if (CheckCommand(command, "debug", "d"))
	{
		debugMode = !debugMode;
		return;
	}

	int myJudg = NONE, result = NONE;
	if (CheckCommand(command, "high", "h"))myJudg = HIGH;
	if (CheckCommand(command, "low", "l"))myJudg = LOW;

	if (myJudg == NONE)return;

	if (nowCard.GetNumber() <= drawCard.GetNumber())result = HIGH;
	else result = LOW;

	if (myJudg == result)
	{
		cout << "Win!!" << endl;
		score++;
	}
	else
	{
		cout << "Lose" << endl;
		state = END;
	}

	Sleep(2 * 1000);

	nowCard = drawCard;
	deck.Next();
}

void GameManager::GameEnd()
{
	std::system("cls");

	cout << "<< SCORE  " << right << setw(15) << score * 100 << "  >>" << endl << endl << endl;
	cout << "Menu( m ) / End( e )" << endl;

	string command;
	cin >> command;

	if (CheckCommand(command, "Menu", "m"))state = MENU;
	if (CheckCommand(command, "exit", "e"))state = EXIT;
}

bool GameManager::CheckCommand(string command, string check, string check2)
{
	if (!check2.empty())
		return regex_match(command, regex(check, regex::icase)) || regex_match(command, regex(check2, regex::icase));

	return regex_match(command, regex(check, regex::icase));
}
#pragma endregion

int main()
{
	GameManager GM = GameManager();
	GM.MainLoop();

	return 0;
}


