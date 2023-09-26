// Programming Example
// Rock, Paper and Scissors

#include <iostream>

using namespace std;

enum objectType { ROCK, PAPER, SCISSORS };

bool validSelection(char c);
objectType retrievePlay();
int gameResult(objectType choice1, objectType choice2);
void displayResults(int totalCount, int count1, int count2);

int main()
{

	int totalPlays = 0;
	int wins1 = 0;
	int wins2 = 0;

	char isPlay;
	cout << "The game starts! Enter Y or y if you want to play, N or n otherwise. " << endl;
	cin >> isPlay;
	cout << endl;
	while (isPlay == 'Y' || isPlay == 'y')
	{
		totalPlays++;
		cout << "Player 1 ";
		objectType p1 = retrievePlay();
		cout << "Player 2 ";
		objectType p2 = retrievePlay();
		int result = gameResult(p1, p2);
		if (result == 1)
			wins1++;
		else if (result == 2)
			wins2++;

		cout << "Enter Y or y if you want to play another round, N or n otherwise. " << endl;
		cin >> isPlay;

	}

	displayResults(totalPlays, wins1, wins2);
	return 0;
}

bool validSelection(char c)
{
	switch (c)
	{
	case 'r':
	case 'R':
	case 'p':
	case 'P':
	case 's':
	case 'S':

		return true;
	default:
		cout << "Invalid input!" << endl;
		return false;
	}
}

objectType retrievePlay()
{
	char ch;
	cout << "Enter your choice : " << endl;
	cin >> ch;
	if (validSelection(ch))
	{
		switch (ch)
		{
		case 'r':
		case 'R':
			return ROCK;
		case 'p':
		case 'P':
			return PAPER;
		case 's':
		case 'S':
			return SCISSORS;

		}
	}
	else
		retrievePlay();
}

int gameResult(objectType choice1, objectType choice2)
{
	if (choice1 == choice2)
	{
		if (choice1 == ROCK)
		{
			cout << "Player1's choice: Rock" << endl;
			cout << "Player2's choice: Rock" << endl;
		}
		else if (choice1 == PAPER)
		{
			cout << "Player1's choice: Paper" << endl;
			cout << "Player2's choice: Paper" << endl;
		}
		else
		{
			cout << "Player1's choice: Scissors" << endl;
			cout << "Player2's choice: Scissors" << endl;
		}
		cout << "It is a tie!" << endl;
		return 0;
	}
	else if (choice1 == PAPER)
	{
		cout << "Player1's choice: Paper" << endl;
		if (choice2 == ROCK)
		{
			cout << "Player2's choice: Rock" << endl;
			cout << "Player 1 wins this round!" << endl;
			return 1;
		}
		else
		{
			cout << "Player2's choice: Scissors" << endl;
			cout << "Player 2 wins this round!" << endl;
			return 2;
		}
	}
	else if (choice1 == ROCK)
	{
		cout << "Player1's choice: Rock" << endl;
		if (choice2 == SCISSORS)
		{
			cout << "Player2's choice: Scissors" << endl;
			cout << "Player 1 wins this round!" << endl;
			return 1;
		}
		else
		{
			cout << "Player2's choice: Paper" << endl;
			cout << "Player 2 wins this round!" << endl;
			return 2;
		}
	}
	else if (choice1 == SCISSORS)
	{
		cout << "Player1's choice: Scissors" << endl;
		if (choice2 == PAPER)
		{
			cout << "Player2's choice: Paper" << endl;
			cout << "Player 1 wins this round!" << endl;
			return 1;
		}
		else
		{
			cout << "Player2's choice: Rock" << endl;
			cout << "Player 2 wins this round!" << endl;
			return 2;
		}
	}

}

void displayResults(int totalCount, int count1, int count2)
{
	cout << "The number of plays is: " << totalCount << endl;
	cout << "The number of wins of Player1 is: " << count1 << endl;
	cout << "The number of wins of Player2 is: " << count2 << endl;
	if (count1 == count2)
		cout << "The final result is a tie!" << endl;
	else if (count1 > count2)
		cout << "The final winner is Player1!" << endl;
	else
		cout << "The final winner is Player2!" << endl;
}
