#pragma once

//----1
namespace myNS
{
	float randomFloat(float a, float b); // random float value
	float createArray(float* pArr, const int SIZE); // create array with float value 
	float printArr(float* pArr, const int SIZE); // print array
	float checkArray(float* pArr, const int SIZE); // check array on positive and negative elements
}

//----2
void checkNums(int num1, int num2); // check numbers on >= or <

//----3
void bubbleSort(); //sorting array with bubble algorithm
int printArr(int* pArr, const int SIZE); // print array

//----4
#pragma pack(push, 1)
struct Employee // struct employee
{
	int id;
	unsigned short age;
	std::string name;
	double salary;
};
#pragma pack(pop)

