#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Header.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin;
	fin.open("t.txt");
	int num;
	int* arr = readArray(fin, num);
	fin.close();
	int kol;
	kol = findnaim(arr, num);
	ofstream fout;
	fout.open("o.txt");
	writeArray(fout, kol);
	fout.close();
	cout << kol << endl;
	delete[]arr;
	return 0;
}