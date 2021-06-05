#include<iostream>

using namespace std;

int main()
{  
//======================== 1

  {
	int num1, num2, summ;

	cout << "Number 1: ";
	cin >> num1;

	cout << "Number 2: ";
	cin >> num2;

	summ = num1 + num2;

	(summ >= 10 && summ <= 20) ? cout << "True" << "\n" : cout << "False" << "\n";
	
  }

//========================

//======================== 2
	
  {	  
	 const int NUM1 = 10, NUM2 = 10;

	  if ((NUM1 == 10 && NUM2 == 10) || ((NUM1 + NUM2) == 10))
	  {
		  cout << "True" << "\n";
	  }
	  else
	  {
		  cout << "False" << "\n";
	  }
  }

//========================

//======================== 3

	{
		cout << "Your numbers: " << "\n";

		for (size_t i = 0; i < 50; i++)
		{
			if ((i % 2) != 0)
			{
				cout << i << " ";
			}
		}

		cout << "\n";
	}

//========================

//======================== 4

	{
		int num;
		bool check = true;
		cout << "Write number to check: ";
	    cin >> num;

		for(size_t i = 2; i < 10; i++ )
		{
		   if(num != i){

			  if((num%i) == 0)
			  {
			 	check = false;
				break;
			  }
			  
		   }
		   else
		   {
			   break;
		   }
		}

		(check) ? cout << "Your number is simple" : cout << "Your number is`t simple";
		cout << "\n";
	}

//========================

//======================== 5

	 {
		size_t yearNum;
		bool leapYear, isDivide4, isDivide100, isDivide400;
				 
		cout << "Write year to check: ";
		cin >> yearNum;

		isDivide4 = yearNum % 4;
		isDivide100 = yearNum % 100;
		isDivide400 = yearNum % 400;

		leapYear = (!isDivide4) ? (!isDivide400) ? true : (!isDivide100 && !isDivide4) ? false : true : false ;
				
		(leapYear) ? cout << yearNum << " is a leap year" : cout << yearNum << " is`t a leap year";							
	 }

//========================

	return 0;
}
