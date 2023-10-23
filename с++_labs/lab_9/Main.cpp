#include <vector>
#include <fstream>
#include <iostream>
#include "Header.h"

using namespace std;

enum Menu
{
	scan_from_file,
	print_to_file,
	min_max_length,
	exit_program
};

int main()
{
	system("chcp 1251");
	int ans;
	Vector p;
	do
	{
		cout << "Выберите пункт меню: " << endl
			<< scan_from_file << " - чтение из файла" << endl
			<< print_to_file << " - вывод в файл" << endl
			<< min_max_length << " - определение мин. и макс. по длине векторов" << endl
			<< exit_program << " - выход из программы" << endl;
		cin >> ans;
		
		switch (ans)
		{
		case scan_from_file:
		{
			string path;
			cout << "Введите название файла: " << endl;
			cin >> path;
			ifstream fin(path + ".txt");
			p.scan(fin);
			fin.close();
			break;
		}

		case print_to_file:
		{
			string path;
			cout << "Введите название файла: " << endl;
			cin >> path;
			ofstream fout(path + ".txt");
			p.print(fout);
			fout.close();
			break;
		}

		case min_max_length:
		{
			std::pair<double, double> max_min = p.computeMinMaxLen();
			cout << "Минимальный вектор: " << max_min.first << "Максимальный вектор: " << max_min.second << endl;
			break;
		}

		case exit_program:
		{
			break;
		}
		}
	} while (ans != exit_program);
	return 0;
}