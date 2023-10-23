#include "Header.h"
#include <fstream>
using namespace std;

int* readArray(istream& fin, int& num)
{
	fin >> num;
	int* a = new int[num];
	for (int i = 0; i < num; i++)
	{
		fin >> a[i];
	}
	return a;
}

int findnaim(int* arr, int num)
{
	int min = arr[0];
	for (int i = 0; i < num; i++)
	{
		if (arr[i] <= min)
		{
			min = arr[i];
		}
	}

	int count = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == min)
		{
			count += 1;
		}
	}
	return count;
}

void writeArray(ostream& fout, int kol)
{
	fout << kol;
}