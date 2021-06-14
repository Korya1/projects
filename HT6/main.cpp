#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "header.h"

//=====================================
// Prototypes
//===================================== 

//=====================================
// 
//===================================== 

int main()
{
//============================================== Task 1
	int* ptrArr1;
	int SIZE_1;
	std::cout << "Task 1 " << "\n";
	std::cout << "Enter size of array: ";
	std::cin >> SIZE_1;

	ptrArr1 = new (std::nothrow) int[SIZE_1];

	calculateFun(ptrArr1, SIZE_1);

	delete[] ptrArr1;
	ptrArr1 = nullptr;
//==============================================

//============================================== Task 2
	srand(time(NULL));

	int** ptrArr2 = nullptr;
	int firstSize = 4;
	int secondSize = 4;

	std::cout << "\n" << "Task 2 " << "\n";
	create_array(ptrArr2, firstSize, secondSize);
	fill_array(ptrArr2, firstSize, secondSize);
	showArray(ptrArr2, firstSize, secondSize);
	delete_array(ptrArr2, firstSize);
//==============================================

//============================================== Task 3
	std::string fileName_1;
	std::string fileName_2;	
	
	std::cout << "\n" << "Task 3 " << "\n";
	std::cout << "Enter first file name: ";
	std::cin >> fileName_1;

	std::cout << "Enter second file name: ";
	std::cin >> fileName_2;

	firstFuncToWrite(fileName_1);
	secondFuncToWrite(fileName_2);	
//==============================================

//============================================== Task 4
	std::string askFile_1;
	std::string askFile_2;
	std::string fileName_3;

	std::cout << "\n" << "Task 4 " << "\n";
	std::cout << "Enter first file to read: ";
	std::cin >> askFile_1;

	std::cout << "Enter second file to read: ";
	std::cin >> askFile_2;

	std::cout << "Enter third file to write: ";
	std::cin >> fileName_3;

	readAndWriteFun(askFile_1, askFile_2, fileName_3);
//==============================================

//============================================== Task 5
	std::string askFileToRead;
	std::string askWord;

	std::cout << "\n" << "Task 5 " << "\n";
	std::cout << "Enter file name to read: ";
	std::cin >> askFileToRead;

	std::cout << "Enter word to find: ";
	std::cin >> askWord;
	
	findWord(askFileToRead, askWord);
//==============================================

	return 0;
}


