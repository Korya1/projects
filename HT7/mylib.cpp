#include <iostream>
#include <string>
#include <fstream>
#include "mylib.h"

#define CHECKNUMS(x, y) ((x) >= 0 ? (x) < (y) ? true : false : false)
#define SwapINT(a, b) {int c = a; a = b; b = c;}
#define SIZEARR 5

//----1
namespace myNS 
{
	float randomFloat(float a, float b) // random float value
	{
		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = b - a;
		float r = random * diff;
		return a + r;
	}

	float createArray(float* pArr, const int SIZE) // create array with float value 
	{
		for (int i = 0; i < SIZE; i++)
		{
			pArr[i] = randomFloat(-5.0, 5.0);
		}
		return 0;
	}

	float printArr(float* pArr, const int SIZE) // print array
	{
		for (int i = 0; i < SIZE; i++)
		{
			std::cout << pArr[i] << "\n";
		}	
		return 0;
	}

	float checkArray(float* pArr, const int SIZE) // check array on positive and negative elements
	{
		std::cout << "\n";
		int tempPos = 0;
		int tempNeg = 0;

		for (int i = 0; i < SIZE; i++)
		{
			(pArr[i] >= 0) ? tempPos++ : tempNeg++;
		}

		std::cout << "Positive elements: " << tempPos << "\n"
			<< "Negative elements: " << tempNeg << "\n";

		std::cout << "\n";

		return 0;
	}
}// my name space

//----2
void checkNums(int num1, int num2) // check numbers on >= or <
{
	std::cout << "\n";
	bool res;
	res = CHECKNUMS(num1, num2);
	if (res)
	{
		std::cout << "true" << "\n";
	}
	else
	{
		std::cout << "false" << "\n";
	}
	std::cout << "\n";
}
//----3
int printArr(int* pArr, const int SIZE) // print array
{
	std::cout << "\n";
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << pArr[i] << " ";
	}
	return 0;
}

void bubbleSort() //sorting array with bubble algorithm
{
	int arr[SIZEARR]{ 0 };
	int el;

	for (int i = 0; i < SIZEARR; i++)
	{
		std::cout << "Enter '" << i + 1 << "' element: " << "\n";
		std::cin >> el;
		arr[i] = el;
	}
	
	printArr(arr, SIZEARR);

	for (int i = 0; i < SIZEARR; i++)
	{
		for (int r = i + 1; r < SIZEARR; r++)
		{
			if (arr[i] < arr[r])
			{
				SwapINT(arr[i], arr[r]);
			}
		}
	}
	
	printArr(arr, SIZEARR);
	std::cout << "\n" << "\n";
}

void emFun() // work with dynamic struct
{
	Employee* em1 = new Employee;

	em1->id = 111338877;
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
}