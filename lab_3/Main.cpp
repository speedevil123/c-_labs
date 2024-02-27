#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "Header.h"

using namespace std;

enum Menu
{
	scan_from_keyboard,
	scan_from_file,
	print_to_display,
	print_to_file,
	sort_of_services,
	poisk,
	exit_program
};

int main()
{
	system("chcp 1251");

	int num = 0, num2 = 0;
	Service* p = nullptr;
	int choice;

	do
	{
		cout << "Выберите пункт меню: " << endl;
		cout << scan_from_keyboard << " - чтение с клавиатуры" << endl
			<< scan_from_file << " - чтение из файла" << endl
			<< print_to_display << " - вывод на экран" << endl
			<< sort_of_services << " - сортировка по отношению цена/качество" << endl
			<< poisk << " - поиск одинаковых услуг" << endl
			<< exit_program << " - выход" << endl;
		cin >> choice;

		switch (choice)
		{
		case scan_from_keyboard:
			if (p != nullptr)
				delete[] p;
			p = scan(cin, num);
			break;
		case scan_from_file:
		{
			if (p != nullptr)
				delete[] p;
			string path;
			cout << "Введите название файла: ";
			cin >> path;
			ifstream fin(path + ".txt");
			p = scan(fin, num);
			fin.close();
			break;
		}

		case print_to_display:
		{
			if (p != nullptr)
				print(cout, p, num);
			else
				cout << "Массив не заполнен!" << endl;
			break;
		}

		case print_to_file:
		{
			string path;
			cout << "Введите название файла: ";
			cin >> path;
			ofstream fout(path + ".txt");
			print(fout, p, num);
			fout.close();
			break;
		}

		case sort_of_services:
		{
			sort(p, p + num, Compare);
			break;
		}

		case poisk:
		{
			string yslyga;
			cout << "Введите услугу, проверяемую на совпадение: ";
			cin >> yslyga;
			Service* poisk22 = finder(p, yslyga, num, num2);
			print(cout, poisk22, num2);
		}

		case exit_program:
		{
			delete[] p;
			break;
		}
		}
	} while (choice != exit_program);

	return 0;
}