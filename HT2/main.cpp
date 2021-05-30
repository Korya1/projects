#include<iostream>

using namespace std;

// ----------------- 2
enum Symbols { EMPTY, SYMBOL_0, SYMBOL_X }; //  Symbols to chose (Empty, 0, X)
enum HorizontalLine { hLINE_01, hLINE_02, hLINE_03 }; //  Horizontal line
enum VerticalLine { vLINE_01, vLINE_02, vLINE_03 }; // Vertical line
enum Colors { C_PINK, C_RED, C_GREEN, C_BLUE, C_BLACK, C_WHITE }; // Colors


int main()
{

	// ----------------- 1
	{
		int firstVar = 2;
		double secondVar = 3.1415926535;
		float thirdVar = 2.32333333;
		short int fourthVar = 22787;
		long long fifthVar = 9'000'000'000;
		bool sixthVar = true;
		char seventhVar = 'x';
	}

	// ----------------- 3
	Symbols e = EMPTY;
	Symbols o = SYMBOL_0;
	Symbols x = SYMBOL_X;

	HorizontalLine hLine1 = hLINE_01;
	HorizontalLine hLine2 = hLINE_02;
	HorizontalLine hLine3 = hLINE_03;

	VerticalLine vLine1 = vLINE_01;
	VerticalLine vLine2 = vLINE_02;
	VerticalLine vLine3 = vLINE_03;

	const int SIZE = 3;
	Symbols symbolsForGame[SIZE][SIZE][SIZE]
	{
		{ {e, o, x }, {e, o, x }, {e, o, x } },
		{ {e, o, x }, {e, o, x }, {e, o, x } },
		{ {e, o, x }, {e, o, x }, {e, o, x } }
	};

	// ----------------- 4

	struct gameSpace
	{
		int sizeOfGameZone, sizeOfInputZone, sizeOfBorders, playerColor, playStep;
		int score;
		string playerName, winner;
		char elForPlay;
		short int verLine, horlLine, inputZones, inputSymbols;
		bool isEmptyInputZone, firstStep, finishGame;
		float timeOnStep;
		bool checkDiagonal, checkHorizontal, checkVertical, restartGame;
	};

	gameSpace player1, player2, gameZone, gameMovement;

	//--- Game Zone
	gameZone.sizeOfGameZone = 100;
	gameZone.sizeOfInputZone = 11;
	gameZone.sizeOfBorders = 1;
	gameZone.verLine = 3;
	gameZone.horlLine = 3;
	gameZone.inputZones = 9;
	gameZone.inputSymbols = 3;

	//--- Player 1
	player1.playerName = "Player_01";
	player1.elForPlay = 'X';
	player1.playerColor = C_GREEN;
	player1.firstStep = true;
	player1.score = 0;

	//--- Player 2
	player2.playerName = "Player_02";
	player2.elForPlay = '0';
	player2.playerColor = C_BLUE;
	player2.firstStep = false;
	player2.score = 0;

	//--- Game Movement
	gameMovement.playStep = symbolsForGame[hLine2][vLine2][x];
	gameMovement.timeOnStep = 59.9;
	gameMovement.isEmptyInputZone = true;
	gameMovement.finishGame = false;
	gameMovement.checkDiagonal = false;
	gameMovement.checkHorizontal = false;
	gameMovement.checkVertical = false;
	gameMovement.restartGame = false;

	return 0;

}
