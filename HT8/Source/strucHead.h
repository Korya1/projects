#pragma once

enum Level
{
	EASY,
	MEDIUM,
	HARD
};

enum Cell
{
	CROSS = 'X',
	ZERO = '0',
	EMPTY = '_'
};

enum GameProgress
{
	WON_HUMAN,
	WON_AI,
	DRAW,
	IN_PROGRESS
};

struct Coord
{
	size_t y;
	size_t x;
};

#pragma pack (push, 1)
struct Field
{
	Cell** ppField = nullptr;
	const size_t SIZE = 3;
	Cell human = EMPTY;
	Cell ai = EMPTY;
	Level lvl = EASY;
	size_t turn = 0;
	GameProgress progress = IN_PROGRESS;
};
#pragma pack (pop)