#include<iostream>

using namespace std;

int main()
{

//=============================== 1/4
	{
				
		extern const int a, b, c, d;
		extern float result;

		result =  a * (b + (static_cast <float>(c) / d));

		cout << result << endl;
	}
//=============================== 	

//=============================== 2
	{
		int a = 21, b;
		cout << "Write num: ";
		cin >> b;

		(b <= a) ? cout << "Dif btwn (21 and " << b << ") = " << a - b << endl
		  
			     : cout << "Dif btwn (21 and " << b << ") * 2 = " << 2*(b-a) << endl;
	}
//=============================== 

//=============================== 3
	{
		const int SIZE = 3;
		int myArr[SIZE][SIZE][SIZE]{ 0 };
		int* pArr = nullptr;

		pArr = &myArr[1][1][1];
		*pArr = 21;

		cout << *pArr << endl;
	}
//===============================+

	return 0;
}
