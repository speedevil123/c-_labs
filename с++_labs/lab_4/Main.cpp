#include <iostream>
#include <fstream>
#include "CarModels.h"

using namespace std;
enum proverki
{
	car_colour_year,
	car_kuzov,
	car_max_speed,

};
enum viborki
{
	list_car_colour_year,
	list_car_kuzov,
	list_car_max_speed,
};
enum Menu
{
	scan_from_file,
	scan_from_keyboard,
	print_to_file,
	print_to_display,
	proverki,
	viborki,
	exit_program
};
int main()
{
	system("chcp 1251");
	CarModelsArray p;
	int menu;
	int menu2;

	do
	{
		cout << "�������� ���� �� ������� ����:" << endl
			<< scan_from_file << " - ��������� ������ ���������� �� �����" << endl
			<< scan_from_keyboard << " - ��������� ������ ���������� �� ����������" << endl
			<< print_to_file << " - ����� � ����" << endl
			<< print_to_display << " - ����� �� �����" << endl
			<< proverki << " - ��������" << endl
			<< viborki << " - �������" << endl
			<< exit_program << " - �����" << endl;
		cin >> menu;

		switch (menu)
		{
		case scan_from_file:
		{
			string path;
			cout << "������� �������� �����: ";
			cin >> path;
			ifstream fin(path + ".txt");
			p.scan(fin);
			fin.close();
			break;
		}
		case scan_from_keyboard:
		{
			p.scan(cin);
			break;
		}
		case print_to_file:
		{
			string path;
			cout << "������� �������� �����: ";
			cin >> path;
			ofstream fout(path + ".txt");
			p.print(fout);
			fout.close();
			break;
		}
		case print_to_display:
		{
			p.print(cout);
			break;
		}
		case proverki:
			cout << car_colour_year << " - ����� �� ���������� ������������ ���� � ������� �� ����� ��������� ����" << endl
				<< car_kuzov << " - ����� �� ���������� �������� ��� ������" << endl
				<< car_max_speed << " - ��������� �� ������������ �������� ���������� � ��������� ���������" << endl;
			cin >> menu2;

			switch (menu2)
			{
			case car_colour_year:
			{
				string color;
				int year;
				int carindex = 0;
				cout << "�������� ������ ��� �������: " << endl;
				p.print(cout);
				cin >> carindex;
				cout << "������� �������� ���� � ��� �������: ";
				cin >> color >> year;
				if (p.proverka1(carindex, color, year) == true)
				{
					cout << "\n�����\n" << endl;
				}
				else
				{
					cout << "\n�� �����\n" << endl;
				}
				break;
			}
			case car_kuzov:
			{
				string kuzov;
				int carindex = 0;
				cout << "�������� ������ ��� �������: " << endl;
				p.print(cout);
				cin >> carindex;
				cout << "������� �������� ��� ������: ";
				cin >> kuzov;
				if (p.proverka2(carindex, kuzov) == true)
				{
					cout << "\n�����\n" << endl;
				}
				else
				{
					cout << "\n�� �����\n" << endl;
				}
				break;
			}
			case car_max_speed:
			{
				int max_speed;
				int min_speed;
				int carindex = 0;
				cout << "�������� ������ ��� �������: " << endl;
				p.print(cout);
				cin >> carindex;
				cout << "����������� � ������������ ��������: " << endl;
				cin >> min_speed >> max_speed;
				if (p.proverka3(carindex, min_speed, max_speed) == true)
				{
					cout << "\n�������� ��������� � ��������� ���������\n" << endl;
				}
				else
				{
					cout << "\n�������� �� ��������� � ��������� ���������\n" << endl;
				}
				break;
			}
			}
		case viborki:
			cout << list_car_colour_year << " - ������ ����������� ������������� �����, ���������� ����� ���������� ����" << endl
				<< list_car_kuzov << " - ������ ����������� � ��������� ����� ������" << endl
				<< list_car_max_speed << " - ������  �����������, �  �������  ������������  ��������  ���������  �  ��������� ��������� " << endl
				<< exit_program << " - �����" << endl;
			cin >> menu2;
			switch (menu2)
			{
			case list_car_colour_year:
			{
				string color;
				int god;
				cout << "������� ���� � ���, �� ������� ����� ��������� ������: ";
				cin >> color >> god;
				CarModelsArray o = p.printColorAndYear(color, god);
				o.print(cout);

				break;
			}
			case list_car_kuzov:
			{
				string kuzov;
				cout << "������� ��� ������, �� �������� ����� ��������� ������: ";
				cin >> kuzov;
				CarModelsArray o = p.printBodyType(kuzov);
				o.print(cout);

				break;
			}
			case list_car_max_speed:
			{
				int max_speed;
				int min_speed;
				cout << "������� ����������� � ������������ �������� �� ������� ����� ��������� ������: ";
				cin >> min_speed >> max_speed;
				CarModelsArray o = p.printMaxSpeed(min_speed, max_speed);
				o.print(cout);
				break;
			}
			case exit_program:
				break;
			}
		}
	} while (menu != exit_program);
	return 0;
}