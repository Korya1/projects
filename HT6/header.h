#pragma once

void __fastcall showArray(int* pArr, int SIZE); // show array
void __fastcall showArray(int**& ppArr, const int SIZE_1, const int SIZE_2); // show double array
void __fastcall calculateFun(int* pArr, int SIZE); // calculate power of 2
void __fastcall create_array(int**& ppArr, const int SIZE_1, const int SIZE_2); // create double dynamic array
void __fastcall delete_array(int**& ppArr, const int SIZE_1); // delete double dynamic array
void __fastcall fill_array(int**& ppArr, const int SIZE_1, const int SIZE_2); // fill double dynamic array

void firstFuncToWrite(std::string fileName); // First function to write txt file
void secondFuncToWrite(std::string fileName); // Second function to write txt file
void readAndWriteFun(std::string fileName_1, std::string fileName_2, std::string thirdFile); // Function to read two files and write to the third
void findWord(std::string fileName, std::string keyWord); // Function to find word in txt file 