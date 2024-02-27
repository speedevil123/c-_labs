#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
	system("chcp 1251");
	string file;
	cout << "Введите название файла решения: ";
	getline(cin, file);
	file += ".txt";
	string path = "t.txt";

	int num;
	string* arr = readArray(path, num);
	printArray(cout, arr, num);
	string* words = getwords(arr, num);

	ofstream fout(file);

	writeResult(fout, words, num);

	fout.close();
	delete[] words;
	delete[] arr;
	return 0;
}