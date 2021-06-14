#include <iostream>
#include <fstream>
#include <string>

//---- show array
void __fastcall showArray(int* pArr, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << pArr[i] << " ";
	}
}


//----1 
// 
// calculate power of 2
void __fastcall calculateFun(int* pArr, const int SIZE)
{
	if (pArr != nullptr) {
		int temp = 1;
		*pArr = temp;

		for (int i = 1; i < SIZE; i++)
		{
			pArr[i] = temp * 2;
			temp = pArr[i];
		}
	}
	else
	{
		std::cout << "Error" << "\n";
	}
	showArray(pArr, SIZE);
	std::cout << "\n";
}

//----2
// 
// show double array
void __fastcall showArray(int**& ppArr, const int SIZE_1, const int SIZE_2)
{
	for (int i = 0; i < SIZE_1; i++)
	{
		for (int j = 0; j < SIZE_2; j++)
		{
			std::cout << ppArr[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

// create double dynamic array
void __fastcall create_array(int**& ppArr, const int SIZE_1, const int SIZE_2)
{
	ppArr = new (std::nothrow) int* [SIZE_1];

	if (ppArr != nullptr) {
		for (int i = 0; i < SIZE_1; i++)
		{
			ppArr[i] = new int[SIZE_2];
		}
	}
}

// delete double dynamic array
void __fastcall delete_array(int**& ppArr, const int SIZE_1)
{
	for (int i = 0; i < SIZE_1; i++)
	{
		delete[] ppArr[i];
	}
	delete[] ppArr;
	ppArr = nullptr;
}

// fill double dynamic array
void __fastcall fill_array(int**& ppArr, const int SIZE_1, const int SIZE_2)
{
	for (int i = 0; i < SIZE_1; i++)
	{
		for (int j = 0; j < SIZE_2; j++)
		{
			ppArr[i][j] = rand() % 10;
		}
	}
}

//----3
// 
// First function to write txt file
void firstFuncToWrite(std::string fileName)
{
	std::ofstream fout(fileName + ".txt");

	fout << "It is a long established fact that a reader will be distracted by the\n" <<
		"readable content of a page when looking at its layout.The point of";

	fout.close();
}

// Second function to write txt file
void secondFuncToWrite(std::string fileName)
{
	std::ofstream fout(fileName + ".txt");

	fout << "using Lorem Ipsum is that it has a more-or-less normal distribution\n" <<
		"of letters, as opposed to using 'Content here, content here',\n" <<
		"making it look like readable English.";

	fout.close();
}

//----4
// 
// Function to read two files and write to the third
void readAndWriteFun(std::string fileName_1, std::string fileName_2, std::string thirdFile)
{
	std::string temp;
	std::ofstream third_out(thirdFile + ".txt");
	std::ifstream firstFile(fileName_1 + ".txt");

	if (firstFile.is_open())
	{
		while (!firstFile.eof())
		{
			getline(firstFile, temp);
			third_out << temp << "\n";
		}
		firstFile.close();
	}

	std::ifstream secondFile(fileName_2 + ".txt");
	if (secondFile.is_open())
	{
		while (!secondFile.eof())
		{
			getline(secondFile, temp);
			third_out << temp << "\n";
		}
		secondFile.close();
	}

	third_out.close();
}
//----5
//
// Function to find word in txt file
void findWord(std::string fileName, std::string keyWord)
{
	std::string str;
	std::ifstream fin(fileName + ".txt");
	bool checkWord = false;

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, str);
			if (str.find(keyWord) != std::string::npos)
			{
				checkWord = true;
				break;
			}
		}
		fin.close();
	}

	if (checkWord)
	{
		std::cout << "We found word - " << keyWord << "!" << "\n";
	}
	else
	{
		std::cout << "We didn`t find " << keyWord << "!" << "\n";
	}
}

