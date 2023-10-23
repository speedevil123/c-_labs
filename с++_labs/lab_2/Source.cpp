#include "Header.h"
#include <fstream>
#include <sstream>
using namespace std;

std::string* readArray(std::string path, int& num)
{
	ifstream fin(path);
	num = 0;
	string tmp;

	while (!fin.eof())
	{
		fin >> tmp;
		++num;
	}

	fin.clear();
	fin.seekg(0);

	string* arr = new string[num];

	for (int i = 0; i < num; i++)
	{
		fin >> arr[i];
	}
	return arr;
}

void printArray(std::ostream& out, std::string* arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		out << arr[i] << endl;
	}
}

std::string* getwords(std::string* arr, int& num)
{
	string* tmp = arr;
	string* sortik = new string[num];
	string* check = new string[num];
	int* povtor = new int[num];

	for (int i = 0; i < num;i++)
	{
		int cnt = 1;
		for (int j = i + 1; j < num; j++)
		{
			if (tmp[i] == tmp[j] && tmp[i] != "NULL")
			{
				check[i] = tmp[i];
				cnt += 1;
				tmp[j] = "NULL";
			}
		}
		povtor[i] = cnt;
	}


	int temp;
	string temp1;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (povtor[j] > povtor[j + 1])
			{
				temp = povtor[j];
				temp1 = check[j];
				povtor[j] = povtor[j + 1];
				check[j] = check[j + 1];
				povtor[j + 1] = temp;
				check[j + 1] = temp1;
			}
		}
	}

	for (int i = 0; i < num; i++)
	{
		if (povtor[i] > 1)
		{
			sortik[i] = check[i];
		}
	}
	return sortik;
}

void writeResult(std::ostream& out, std::string* sort, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		out << sort[i] << endl;
	}
}