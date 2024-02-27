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
		cout << "Выберите один из пунктов меню:" << endl
			<< scan_from_file << " - Заполнить массив значениями из файла" << endl
			<< scan_from_keyboard << " - Заполнить массив значениями из клавиатуры" << endl
			<< print_to_file << " - Вывод в файл" << endl
			<< print_to_display << " - Вывод на экран" << endl
			<< proverki << " - Проверки" << endl
			<< viborki << " - Выборки" << endl
			<< exit_program << " - Выход" << endl;
		cin >> menu;

		switch (menu)
		{
		case scan_from_file:
		{
			string path;
			cout << "Введите название файла: ";
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
			cout << "Введите название файла: ";
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
			cout << car_colour_year << " - Имеет ли автомобиль определенный цвет и выпущен ли после заданного года" << endl
				<< car_kuzov << " - Имеет ли автомобиль заданный вид кузова" << endl
				<< car_max_speed << " - Находится ли максимальная скорость автомобиля в указанном интервале" << endl;
			cin >> menu2;

			switch (menu2)
			{
			case car_colour_year:
			{
				string color;
				int year;
				int carindex = 0;
				cout << "Выберите модель для анализа: " << endl;
				p.print(cout);
				cin >> carindex;
				cout << "Укажите желаемый цвет и год выпуска: ";
				cin >> color >> year;
				if (p.proverka1(carindex, color, year) == true)
				{
					cout << "\nИмеет\n" << endl;
				}
				else
				{
					cout << "\nНе имеет\n" << endl;
				}
				break;
			}
			case car_kuzov:
			{
				string kuzov;
				int carindex = 0;
				cout << "Выберите модель для анализа: " << endl;
				p.print(cout);
				cin >> carindex;
				cout << "Укажите желаемый вид кузова: ";
				cin >> kuzov;
				if (p.proverka2(carindex, kuzov) == true)
				{
					cout << "\nИмеет\n" << endl;
				}
				else
				{
					cout << "\nНе имеет\n" << endl;
				}
				break;
			}
			case car_max_speed:
			{
				int max_speed;
				int min_speed;
				int carindex = 0;
				cout << "Выберите модель для анализа: " << endl;
				p.print(cout);
				cin >> carindex;
				cout << "Минимальную и максимальную скорость: " << endl;
				cin >> min_speed >> max_speed;
				if (p.proverka3(carindex, min_speed, max_speed) == true)
				{
					cout << "\nСкорость находится в указанном диапазоне\n" << endl;
				}
				else
				{
					cout << "\nСкорость не находится в указанном диапазоне\n" << endl;
				}
				break;
			}
			}
		case viborki:
			cout << list_car_colour_year << " - Список автомобилей определенного цвета, выпущенных после указанного года" << endl
				<< list_car_kuzov << " - Список автомобилей с указанным видом кузова" << endl
				<< list_car_max_speed << " - Список  автомобилей, у  которых  максимальная  скорость  находится  в  указанном интервале " << endl
				<< exit_program << " - Выход" << endl;
			cin >> menu2;
			switch (menu2)
			{
			case list_car_colour_year:
			{
				string color;
				int god;
				cout << "Введите цвет и год, по которым будет составлен список: ";
				cin >> color >> god;
				CarModelsArray o = p.printColorAndYear(color, god);
				o.print(cout);

				break;
			}
			case list_car_kuzov:
			{
				string kuzov;
				cout << "Введите тип кузова, по которому будет составлен список: ";
				cin >> kuzov;
				CarModelsArray o = p.printBodyType(kuzov);
				o.print(cout);

				break;
			}
			case list_car_max_speed:
			{
				int max_speed;
				int min_speed;
				cout << "Введите минимальную и максимальную скорость по которым будет составлен список: ";
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