#include<iostream>

using namespace std;

//=====================================
// Prototypes
//===================================== 
void showArr(int* pArr, int SIZE); // show array
void doubleArray(double* pArr, int SIZE); // task 1
void changeArr(int* pArr, int SIZE); // task 2
void autoFill(int* pArr, int SIZE); // task 3
void shiftArr(int* pArr, int SIZE, int n); // task 4
void checkBalance(int* pArr, int SIZE); // task 5

//=====================================
// 
//===================================== 

int main()
{

	//============================================== Task 1
	const int SIZE_1 = 5;
	double arr1[SIZE_1]{ 9.145, 12.1, 3.7, 12.5, 4.0 };

	doubleArray(arr1, SIZE_1);
	//==============================================	


	//============================================== Task 2
	const int SIZE_2 = 10;
	int arr2[SIZE_2]{ 1, 1, 0, 0, 1, 0, 1, 1, 1, 0 };

	changeArr(arr2, SIZE_2);
	//==============================================

	//============================================== Task 3
	const int SIZE_3 = 8;
	int arr3[SIZE_3]{ 0 };

	autoFill(arr3, SIZE_3);

	//==============================================

	//============================================== Task 4
	const int SIZE_4 = 5;
	int arr4[SIZE_4]{ 1, 2, 3, 4, 5 };

	shiftArr(arr4, SIZE_4, 1);

	//==============================================

	//============================================== Task 5
	const int SIZE_5 = 6;
	int arr5[SIZE_5]{ 1, 1, 1, 2, 1, 5 };

	checkBalance(arr5, SIZE_5);

	//==============================================


	return 0;
}

//---- show array
void showArr(int* pArr, int SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << pArr[i] << " ";
	}
}


//----1
void doubleArray(double* pArr, int SIZE)
{
	cout << "Task 1" << "\n";
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << *(pArr + i) << "\t";
	}
	cout << "\n" << "\n";
}

//----2
void changeArr(int* pArr, int SIZE)
{
	cout << "Task 2" << "\n";
	showArr(pArr, SIZE);
	for (size_t i = 0; i < SIZE; i++)
	{
		pArr[i] ^= 0b00000001;
	}
	cout << "\n";
	showArr(pArr, SIZE);
	cout << "\n" << "\n";
}

//----3
void autoFill(int* pArr, int SIZE)
{
	cout << "Task 3" << "\n";
	for (size_t i = 0; i < SIZE; i++)
	{
		pArr[i] = (i * 3) + 1;
	}

	showArr(pArr, SIZE);
	cout << "\n" << "\n";
}


//----4
void shiftArr(int* pArr, int SIZE, int n)
{
	cout << "Task 4" << "\n";
	showArr(pArr, SIZE);
	cout << "\n";
	if (n > 0) {
		for (int i = 0; i < n; i++) {

			int temp = pArr[0];
			pArr[0] = pArr[SIZE - 1];

			for (int j = 1; j < SIZE - 1; j++) {
				pArr[SIZE - j] = pArr[SIZE - j - 1];
			}

			pArr[1] = temp;
		}
	}
	else if (n < 0) {
		for (int i = 0; i > n; i--) {

			int temp = pArr[SIZE - 1];
			pArr[SIZE - 1] = pArr[0];

			for (int j = 1; j < SIZE - 1; j++) {
				pArr[j - 1] = pArr[j];
			}

			pArr[SIZE - 2] = temp;
		}
	}
	showArr(pArr, SIZE);
	cout << "\n" << "\n";
}

//----5
void checkBalance(int* pArr, int SIZE)
{
	cout << "Task 5" << "\n";
	int compareLeft = 0, compareRight = 0;

	for (int i = 0; i < SIZE - 1; i++)
	{
		compareLeft += pArr[i];
		compareRight = 0;

		for (int j = i + 1; j < SIZE; j++)
		{
			compareRight += pArr[j];
		}

		if (compareLeft == compareRight)
		{
			break;
		}

	}
	(compareLeft == compareRight) ? cout << "True" << "\n" : cout << "False" << "\n";

}
