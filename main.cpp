#include <iostream>
#include <string>
#include <ctime>

#define LOG(x) cout << x << endl

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int width = 35;
string playerChoice;
string botChoice;
string winMessage;
bool playerIsChoicset;


void Draw()
{
	system("cls");

	for (int i = 0; i < width; i++)
		cout << "\xB2";
	cout << endl;
	cout << endl;
	
	cout << "Enter one of the letters to choice:" << endl;
	cout << "Enter (R) for Rock." << endl;
	cout << "Enter (p) for Paper." << endl;
	cout << "Enter (S) for Scissors." << endl;

	if (playerIsChoicset)
	{
		cout << endl;
		cout << "You choicest: " << playerChoice << endl;
		cout << "Bot choicest: " << botChoice << endl;
		cout << endl;
		
		cout << winMessage << endl;
	}

	cout << endl;	
	for (int i = 0; i < width; i++)
		cout << "\xB2";
	cout << endl;

	if (playerIsChoicset)
		cout << "Enter (Q) to quit game or play again: ";
}


void CheckForUserChoice(string object);
void Input()
{
	char userInput;
	cin >> userInput;

	if (userInput == 'q' || userInput == 'Q')
		playerIsChoicset = false;

	if (userInput == 'R' || userInput == 'r')
		CheckForUserChoice("Rock");
	else if (userInput == 'P' || userInput == 'p')
		CheckForUserChoice("Paper");
	else if (userInput == 'S' || userInput == 's')
		CheckForUserChoice("Scissors");
	else
		cout << "\x07";
}

void Logic()
{
	if (playerChoice == "Rock" && botChoice == "Scissors")
		winMessage = "You Win!";
	else if (playerChoice == "Rock" && botChoice == "Paper")
		winMessage = "You Lose!";
	else if (playerChoice == "Paper" && botChoice == "Rock")
		winMessage = "You Win!";
	else if (playerChoice == "Paper" && botChoice == "Scissors")
		winMessage = "You lose!";
	else if (playerChoice == "Scissors" && botChoice == "Rock")
		winMessage = "You lose!";
	else if (playerChoice == "Scissors" && botChoice == "Paper")
		winMessage = "You Win!";
	else
		winMessage = "Nobody wins it's a Tie!";
}

void Run()
{
	Draw();
	Input();
	Logic();
	Draw();
}


int main()
{
	srand(time(NULL));
	
	Run();

	while (playerIsChoicset != false)
	{
		Run();
	}
}

void GenrateRandomChoice()
{
	int random = rand() % 3;

	if (random == 0)
		botChoice = "Rock";
	else if (random == 1)
		botChoice = "Paper";
	else
		botChoice = "Scissors";
}

void CheckForUserChoice(string object)
{
	playerChoice = object;
	playerIsChoicset = true;
	GenrateRandomChoice();
}