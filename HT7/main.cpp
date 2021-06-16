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

	Employee* em1 = new Employee;

	em1->id = 99338877;
	em1->age = 28;
	em1->name = "Vasya";
	em1->salary = 11'000;	

	std::cout << em1->id << "\n";
	std::cout << em1->age << "\n";
	std::cout << em1->name << "\n";
	std::cout << em1->salary << "\n";

	std::cout << "\nStruct size: " << sizeof(em1) << "\n";

	std::ofstream fout("myStruct.txt");

	fout << em1->id << "\n";
	fout << em1->age << "\n";
	fout << em1->name << "\n";
	fout << em1->salary << "\n";

	fout.close();

	delete em1;
//==============================================

	return 0;
}


