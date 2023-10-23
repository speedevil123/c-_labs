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
		cout << "�������� ����� ����: " << endl;
		cout << scan_from_keyboard << " - ������ � ����������" << endl
			<< fill_with_random_numbers << " - ��������� ���������� ����������" << endl
			<< print_to_display << " - ����� �� �����" << endl
			<< operations << " - �������� ��� ���������" << endl
			<< average_number << " - �������� ����. � ���. �������� � �������" << endl
			<< sort_vector_average << " - ���������� �������� �� ����. � ���. ��������" << endl
			<< exit_program << " - �����" << endl;
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
			cout << "������� ���������� �������� �����: ";
			cin >> size;
			p = new Vector[size];

			for (int i = 0; i < size; i++)
			{
				cout << "������� ����� ������� ��� �������: " << i + 1 << endl;
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
			cout << "������� ���������� �������� �����: ";
			cin >> size;
			p = new Vector[size];
			cout << "������� �� ������: ";
			cin >> sizeVector;
			cout << "������� �������� �������� (������� � ��������): ";
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
				cout << "������ ��� �������: " << i + 1 << endl;
				cout << p[i] << endl;
			}
			break;
		}

		case operations:
		{
			int firstVector, secondVector;
			Vector result;
			cout << "�������� 2 ������� �����: ";
			for (int i = 0; i < size; i++)
			{
				cout << "����� �������: " << i + 1 << endl;
				cout << p[i] << endl;
			}
			cout << "������: ";
			cin >> firstVector;
			cout << "������: ";
			cin >> secondVector;
			cout << slojenie << " - ��������" << endl
				<< vichitanie << " - ���������" << endl
				<< ymnojenie << " - ���������" << endl;
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
			cout << "�������� ������: " << endl;

			for (int i = 0; i < size; i++)
			{
				cout << "������ ��� �������: " << i + 1 << endl;
				cout << p[i] << endl;
			}
			cin >> variant;
			cout << "��������: ";
			cout << p[--variant].GetMax() << endl;
			cout << "�������: ";
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