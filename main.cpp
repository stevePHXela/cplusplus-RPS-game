#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <array>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::string;


string playerChoice;
string botChoice;
string writeMessage;

std::map<string, string> winCondition =
{
	{"Rock", "Scissor"},
	{"Paper", "Rock"},
	{"Scissor", "Paper"}
};

struct Options
{
	static const char Quit = 'q';
	static const char Rock = 'r';
	static const char Paper = 'p';
	static const char Scissors = 's';
};

void Draw()
{
	system("cls");
	const int BORDER_WIDTH = 35;
	const string BORDER_CHAR = "\xB2";

	for (int i = 0; i < BORDER_WIDTH; i++)
	{
		cout << BORDER_CHAR;
	}
	cout << endl;
	cout << endl;
	
	cout << "Enter one of the letters to choice:" << endl;
	cout << "Enter (R) for Rock." << endl;
	cout << "Enter (p) for Paper." << endl;
	cout << "Enter (S) for Scissor." << endl;

	if (!playerChoice.empty() && !botChoice.empty())
	{
		cout << endl;
		cout << "You choicest: " << playerChoice << endl;
		cout << "Bot choicest: " << botChoice << endl;
		cout << endl;
		
		cout << writeMessage << endl;
	}

	cout << endl;	
	for (int i = 0; i < BORDER_WIDTH; i++)
	{
		cout << BORDER_CHAR;
 	}
	cout << endl;

	if (!playerChoice.empty() && !botChoice.empty())
	{
		cout << "Enter (Q) to quit game or play again: ";
	}
}


void Input()
{
	const string windowsAlertSound = "\x07";
	char userInput;

	cin >> userInput;
	userInput = (char)std::tolower(userInput);

	if (userInput == Options::Quit)
	{
		exit(EXIT_SUCCESS);
	}

	if (userInput == Options::Rock)
		playerChoice = "Rock";
	else if (userInput == Options::Paper)
		playerChoice = "Paper";
	else if (userInput == Options::Scissors)
		playerChoice = "Scissor";
	else
		if(userInput != Options::Quit)
			cout << windowsAlertSound;
}

string GenrateRandomChoice(const std::array<string, 3>& choices);
int compareOptions(string& option1, string& option2);
void Logic()
{
	const std::array<string, 3> CHOICES = { "Rock", "Paper", "Scissor" };
	botChoice = GenrateRandomChoice(CHOICES);

	int winner = compareOptions(playerChoice, botChoice);

	if (winner == 1)
		writeMessage = "You Win!";
	else if (winner == -1)
		writeMessage = "You Lose";
	else
		writeMessage = "It's a Tie";

}

string GenrateRandomChoice(const std::array<string, 3>& choices)
{
	return choices[rand() % 3];
}

int compareOptions(string& option1, string& option2)
{
	if (option1 == option2)
		return 0;

	return option2 == winCondition[option1] ? 1 : -1;
}

void Run()
{
	Draw();
	Input();
	Logic();
}


int main()
{
	srand(time(NULL));

	while (true)
	{
		Run();
	}
}