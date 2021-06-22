#pragma once
#include "strucHead.h"

void clearF(); // Clear screan
int32_t getRandomNum(int32_t min, int32_t max);// Random value
void chooseLvl(Field& f); // Choose level
void initField(Field& f); // Initialization field 
void delInitField(Field& f); // Delete field
void printField(Field& f); // Print field 

GameProgress getWon(Field& f); // Get result

Coord getHumanCoord(Field& f); // Get step (Human)

Coord getAiCoordEasy(Field& f); // Get step easy (Computer)
Coord getAiCoordMedium(Field& f); // Get step medium (Computer)
Coord getAiCoordHard(Field& f); // Get step hard (Computer)

void getCongrats(GameProgress progress); // Print result

void game(); //Game