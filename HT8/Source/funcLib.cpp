#include <iostream>
#include <random>
#include <chrono>
#include <stdlib.h>
#include "funcLib.h"
#include <limits>

// Clear screan
void clearF()
{
	system("cls");
}

// Random value
int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::mt19937_64 generator(seed);
	std::uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

//Choose level
void chooseLvl(Field& f)
{
	size_t l;

	std::cout << "\n   " << "Enter Level type\n\n" <<
		"   Level 'Easy'   : 1\n" <<
		"   Level 'Medium' : 2\n" <<
		"   Level 'Hard'   : 3\n\n";

	std::cout << "   " << "Enter: ";
	std::cin >> l;

	while ((l < 1 || l > 3) || !std::cin.good())
	{
		clearF();

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "\n   " << "Error!!! Enter correct Level type\n";

		std::cout << "\n   " << "Enter Level type\n\n" <<
			"   Level 'Easy'   : 1\n" <<
			"   Level 'Medium' : 2\n" <<
			"   Level 'Hard'   : 3\n\n";

		std::cout << "   " << "Enter: ";
		std::cin >> l;
	}

	if (l == 1)
	{
		f.lvl = EASY;
	}
	else if (l == 2)
	{
		f.lvl = MEDIUM;
	}
	else if (l == 3)
	{
		f.lvl = HARD;
	}
}

// Initialization field 
void initField(Field& f)
{
	f.ppField = new Cell * [f.SIZE];

	for (size_t i = 0; i < f.SIZE; i++)
	{
		f.ppField[i] = new Cell[f.SIZE];
	}

	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			f.ppField[y][x] = EMPTY;
		}
	}

	if (getRandomNum(0, 1000) < 500)
	{
		f.human = CROSS;
		f.ai = ZERO;
		f.turn = 0;
	}
	else
	{
		f.human = ZERO;
		f.ai = CROSS;
		f.turn = 1;
	}
}

// Delete field 
void delInitField(Field& f)
{
	for (size_t i = 0; i < f.SIZE; i++)
	{
		delete[] f.ppField[i];
	}

	delete[] f.ppField;
	f.ppField = nullptr;
}


// Print field 
void printField(Field& f)
{
	if (f.lvl == EASY)
	{
		std::cout << "\n\n  " << "----Level Easy----";
	}

	if (f.lvl == MEDIUM)
	{
		std::cout << "\n\n " << "----Level Medium----";
	}

	if (f.lvl == HARD)
	{
		std::cout << "\n\n  " << "----Level Hard----";
	}

	std::cout << "\n" << "\n";
	std::cout << "        ";

	for (size_t x = 0; x < f.SIZE; x++)
	{
		std::cout << "x" << x + 1 << "  ";
	}

	std::cout << "\n" << "\n";

	for (size_t y = 0; y < f.SIZE; y++)
	{

		std::cout << "  y" << y + 1 << "  | ";

		for (size_t x = 0; x < f.SIZE; x++)
		{
			std::cout << static_cast<char>(f.ppField[y][x]) << " | ";
		}

		std::cout << "\n" << "\n";
	}

	std::cout << "   Human play: " << static_cast<char>(f.human) << "\n";
	std::cout << "Computer play: " << static_cast<char>(f.ai) << "\n" << "\n";

}

// Get result
GameProgress getWon(Field& f)
{
	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][0] == f.ppField[y][1] && f.ppField[y][0] == f.ppField[y][2])
			{
				if (f.ppField[y][0] == f.human)
				{
					return WON_HUMAN;
				}
				else if (f.ppField[y][0] == f.ai)
				{
					return WON_AI;
				}
			}
		}
	}

	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[0][x] == f.ppField[1][x] && f.ppField[0][x] == f.ppField[2][x])
			{
				if (f.ppField[0][x] == f.human)
				{
					return WON_HUMAN;
				}
				else if (f.ppField[0][x] == f.ai)
				{
					return WON_AI;
				}
			}
		}
	}

	if (f.ppField[1][1] == f.ppField[0][2] && f.ppField[1][1] == f.ppField[2][0])
	{
		if (f.ppField[1][1] == f.human)
		{
			return WON_HUMAN;
		}
		else if (f.ppField[1][1] == f.ai)
		{
			return WON_AI;
		}
	}

	if (f.ppField[1][1] == f.ppField[0][0] && f.ppField[1][1] == f.ppField[2][2])
	{
		if (f.ppField[1][1] == f.human)
		{
			return WON_HUMAN;
		}
		else if (f.ppField[1][1] == f.ai)
		{
			return WON_AI;
		}
	}

	bool checkDraw = false;

	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				checkDraw = false;
				break;
			}
			else
			{
				checkDraw = true;
			}
		}

		if (!checkDraw)
		{
			break;
		}
	}

	if (checkDraw)
	{
		return DRAW;
	}

	return IN_PROGRESS;
}

// Get step (Human)
Coord getHumanCoord(Field& f)
{
	Coord c;

	std::cout << "Enter 'X' coord: ";
	std::cin >> c.x;

	std::cout << "Enter 'Y' coord: ";
	std::cin >> c.y;

	while (c.y < 1 || c.x < 1 || c.y > 3 || c.x > 3 || f.ppField[c.y - 1][c.x - 1] != EMPTY || !std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		

		std::cout << "\n\n   " << "Error!!! Enter correct Level type\n\n";

		std::cout << "Enter 'X' coord: ";
		std::cin >> c.x;

		std::cout << "Enter 'Y' coord: ";
		std::cin >> c.y;
	}

	c.y--;
	c.x--;

	return c;
}

// Get step easy (Computer)
Coord getAiCoordEasy(Field& f)
{
	Coord arr[9]{ 0 };
	size_t count = 0;

	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				arr[count++] = { y, x };
			}
		}
	}

	if (count > 0)
	{
		const size_t index = getRandomNum(0, 1000) % count;
		return arr[index];
	}

	return { 1, 1 };
}

// Get step medium (Computer)
Coord getAiCoordMedium(Field& f)
{
	//First step
	if (f.ppField[1][1] == EMPTY)
	{
		return { 1, 1 };
	}

	Coord arr[4]{ 0 };
	size_t count;

	count = 0;
	//Corners
	if (f.ppField[0][0] == EMPTY)
	{
		arr[count++] = { 0, 0 };
	}

	if (f.ppField[0][2] == EMPTY)
	{
		arr[count++] = { 0, 2 };
	}

	if (f.ppField[2][2] == EMPTY)
	{
		arr[count++] = { 2, 2 };
	}

	if (f.ppField[2][0] == EMPTY)
	{
		arr[count++] = { 2, 0 };
	}

	if (count > 0)
	{
		const size_t index = getRandomNum(0, 1000) % count;
		return arr[index];
	}

	//Other
	count = 0;
	if (f.ppField[0][1] == EMPTY)
	{
		arr[count++] = { 0, 1 };
	}

	if (f.ppField[1][2] == EMPTY)
	{
		arr[count++] = { 1, 2 };
	}

	if (f.ppField[2][1] == EMPTY)
	{
		arr[count++] = { 2, 1 };
	}

	if (f.ppField[1][0] == EMPTY)
	{
		arr[count++] = { 1, 0 };
	}

	if (count > 0)
	{
		const size_t index = getRandomNum(0, 1000) % count;
		return arr[index];
	}

	return { 1, 1 };
}

// Get step hard (Computer)
Coord getAiCoordHard(Field& f)
{
	//pre win
	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				f.ppField[y][x] = f.ai;
				if (getWon(f) == WON_AI)
				{
					f.ppField[y][x] = EMPTY;
					return { y, x };
				}
				f.ppField[y][x] = EMPTY;
			}
		}
	}

	//pre fail
	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				f.ppField[y][x] = f.human;
				if (getWon(f) == WON_HUMAN)
				{
					f.ppField[y][x] = EMPTY;
					return { y, x };
				}
				f.ppField[y][x] = EMPTY;
			}
		}
	}

	Coord arr[4]{ 0 };
	size_t count = 0;

	//First step
	if (f.ppField[1][1] == EMPTY)
	{
		return { 1, 1 };
	}

	//Corners
	if (f.ppField[0][0] == EMPTY)
	{
		arr[count++] = { 0, 0 };
	}

	if (f.ppField[0][2] == EMPTY)
	{
		arr[count++] = { 0, 2 };
	}

	if (f.ppField[2][2] == EMPTY)
	{
		arr[count++] = { 2, 2 };
	}

	if (f.ppField[2][0] == EMPTY)
	{
		arr[count++] = { 2, 0 };
	}

	if (count > 0)
	{
		const size_t index = getRandomNum(0, 1000) % count;
		return arr[index];
	}

	//Other
	count = 0;

	if (f.ppField[0][1] == EMPTY)
	{
		arr[count++] = { 0, 1 };
	}

	if (f.ppField[1][2] == EMPTY)
	{
		arr[count++] = { 1, 2 };
	}

	if (f.ppField[2][1] == EMPTY)
	{
		arr[count++] = { 2, 1 };
	}

	if (f.ppField[1][0] == EMPTY)
	{
		arr[count++] = { 1, 0 };
	}

	if (count > 0)
	{
		const size_t index = getRandomNum(0, 1000) % count;
		return arr[index];
	}

	return { 1, 1 };
}

// Print result
void getCongrats(GameProgress progress)
{

	if (progress == WON_HUMAN)
	{
		std::cout << "Human won!" << "\n";
	}
	else if (progress == WON_AI)
	{
		std::cout << "Computer won!" << "\n";
	}
	else if (progress == DRAW)
	{
		std::cout << "Draw..." << "\n";
	}
	std::cout << "\n";
}


// Game
void game()
{
	Field myField;

	chooseLvl(myField);
	initField(myField);

	clearF();
	printField(myField);

	do
	{
		if (myField.turn % 2 == 0)
		{
			Coord c = getHumanCoord(myField);
			myField.ppField[c.y][c.x] = myField.human;
		}
		else
		{
			if (myField.lvl == EASY)
			{
				Coord c = getAiCoordEasy(myField);
				myField.ppField[c.y][c.x] = myField.ai;
			}

			if (myField.lvl == MEDIUM)
			{
				Coord c = getAiCoordMedium(myField);
				myField.ppField[c.y][c.x] = myField.ai;
			}

			if (myField.lvl == HARD)
			{
				Coord c = getAiCoordHard(myField);
				myField.ppField[c.y][c.x] = myField.ai;
			}
		}

		myField.turn++;

		clearF();
		printField(myField);

		myField.progress = getWon(myField);

	} while (myField.progress == IN_PROGRESS);

	getCongrats(myField.progress);

	delInitField(myField);
}