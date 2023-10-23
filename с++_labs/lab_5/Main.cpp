#include <iostream>
#include <fstream>
#include "Header.h"
#include <algorithm>
#include <iomanip>

using namespace std;

enum operations
{
	slojenie,
	vichitanie,
	ymnojenie

};

enum Menu
{
	scan_from_keyboard,
	fill_with_random_numbers,
	print_to_display,
	operations,
	average_number,
	sort_vector_average,
	exit_program
};

int main()
{
	system("chcp 1251");

	int menu, menu2;
	srand(time(NULL));
	int size;
	Vector* p = nullptr;

	do
	{
		cout << "Выберите пункт меню: " << endl;
		cout << scan_from_keyboard << " - чтение с клавиатуры" << endl
			<< fill_with_random_numbers << " - заполнить случайными значениями" << endl
			<< print_to_display << " - вывод на экран" << endl
			<< operations << " - операции над векторами" << endl
			<< average_number << " - получить макс. и мин. значения у вектора" << endl
			<< sort_vector_average << " - сортировка векторов по макс. и мин. значению" << endl
			<< exit_program << " - выход" << endl;
		cin >> menu;

		switch (menu)
		{
		case scan_from_keyboard:
		{
			if (p != nullptr)
			{
				delete[] p;
				size = 0;
			}
			cout << "Введите количество векторов чисел: ";
			cin >> size;
			p = new Vector[size];

			for (int i = 0; i < size; i++)
			{
				cout << "Введите числа вектора под номером: " << i + 1 << endl;
				cin >> p[i];
			}
			break;
		}

		case fill_with_random_numbers:
		{
			if (p != nullptr)
			{
				delete[] p;
				size = 0;
			}
			int sizeVector;
			double min, max;
			cout << "Введите количество векторов чисел: ";
			cin >> size;
			p = new Vector[size];
			cout << "Введите их размер: ";
			cin >> sizeVector;
			cout << "Введите диапазон значений (минимум и максимум): ";
			cin >> min >> max;
			for (int i = 0; i < size; i++)
			{
				p[i].GenerateValue(min, max, sizeVector);
			}
			break;
		}

		case print_to_display:
		{
			for (int i = 0; i < size; i++)
			{
				cout << "Вектор под номером: " << i + 1 << endl;
				cout << p[i] << endl;
			}
			break;
		}

		case operations:
		{
			int firstVector, secondVector;
			Vector result;
			cout << "Выберите 2 вектора чисел: ";
			for (int i = 0; i < size; i++)
			{
				cout << "Номер вектора: " << i + 1 << endl;
				cout << p[i] << endl;
			}
			cout << "Первый: ";
			cin >> firstVector;
			cout << "Второй: ";
			cin >> secondVector;
			cout << slojenie << " - сложение" << endl
				<< vichitanie << " - вычитание" << endl
				<< ymnojenie << " - умножение" << endl;
			cin >> menu2;

			switch (menu2)
			{
			
			case slojenie:
			{
				result = p[--firstVector] + p[--secondVector];
				cout << result;
				break;
			}

			case vichitanie:
			{
				result = p[--firstVector] - p[--secondVector];
				cout << result;
				break;
			}

			case ymnojenie:
			{
				result = p[--firstVector] * p[--secondVector];
				cout << result;
				break;
			}
			}
			break;
		}

		case average_number:
		{
			int variant;
			cout << "Выберите вектор: " << endl;

			for (int i = 0; i < size; i++)
			{
				cout << "Вектор под номером: " << i + 1 << endl;
				cout << p[i] << endl;
			}
			cin >> variant;
			cout << "Максимум: ";
			cout << p[--variant].GetMax() << endl;
			cout << "Минимум: ";
			cout << p[variant].GetMin() << endl;
			break;
		}

		case sort_vector_average:
		{
			Vector* h = sort_mas(p, size);
			for (int i = 0; i < size; i++)
			{
				cout << p[i] << endl;
			}
			break;
		}
		}
	} while (menu != exit_program);
	return 0;
}