#include <iostream>
#include <random>
#include <chrono>
#include <stdlib.h>
#include "funcLib.h"
#include <limits>

int main()
{
	bool ask = false;
	char answ;
	do
	{
		clearF();
		game();

		do
		{			
			std::cout << "\n\n   Play again? [y/n]: ";
			std::cin >> answ;

		} while (!std::cin.fail() && answ != 'y' && answ != 'n');

		if (answ == 'y')
		{
			ask = true;
		}
		else if(answ == 'n')
		{
			ask = false;
		}

	} while (ask);
	

	system("pause");
	return 0;
}


