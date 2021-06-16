#include <iostream>
#include <fstream>
#include "mylib.h"
#include <string>

int main()
{

//============================================== Task 1
	std::cout << "Task 1/5" <<
		"\n=================\n";

	const int SIZE = 7;
	float* ptrArr;
	ptrArr = new float[SIZE];

	myNS::createArray(ptrArr, SIZE);
	myNS::printArr(ptrArr, SIZE);
	myNS::checkArray(ptrArr, SIZE);

	delete[] ptrArr;
	ptrArr = nullptr;
//==============================================

//============================================== Task 2	
	std::cout << "Task 2" <<
		"\n=================\n";

	int num1, num2;

	std::cout << "Enter first element: " << "\n";
	std::cin >> num1;

	std::cout << "Enter second element: " << "\n";
	std::cin >> num2;

	checkNums(num1, num2);
//==============================================

//============================================== Task 3
	std::cout << "Task 3" <<
		"\n=================\n";

	bubbleSort();
//==============================================

//============================================== Task 4
	std::cout << "Task 4" << 
		"\n=================\n";

	emFun();
//==============================================

	return 0;
}


