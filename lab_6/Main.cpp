#include "CargoVehicle.h"
#include "Lorry.h"
#include "Ship.h"
#include "TransportCompany.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

enum Menu
{
	scan_from_keyboard,
	scan_from_file,
	print_to_display,
	print_to_file,
	nas_punkti,
	perevoz_obiem_diapazon,
	vivod_harac,
	exit_program
};

int main()
{
	system("chcp 1251");

	int ans;
	TransportCompany collection;

	do
	{
		cout << "Выберите пункт меню: " << endl;
		cout << scan_from_keyboard << " - чтение с клавиатуры" << endl
			<< scan_from_file << " - чтение из файла" << endl
			<< print_to_display << " - вывод на экран" << endl
			<< print_to_file << " - вывод в файл" << endl
			<< nas_punkti << " - вывод количества населенных пунктов" << endl
			<< perevoz_obiem_diapazon << " - отображение сведений объектов, у которых объём соответствует указанному диапазону" << endl
			<< vivod_harac << " - вывод характеристик массива объеков" << endl
			<< exit_program << " - выход" << endl;
		cin >> ans;
		switch (ans)
		{
		case scan_from_keyboard:
		{
			cin >> collection;
			break;
		}

		case scan_from_file:
		{
			string path;
			cout << "Введите имя файла: ";
			cin >> path;
			ifstream fin(path);
			fin >> collection;
			fin.close();
			break;
		}

		case print_to_display:
		{
			cout << collection;
			break;
		}

		case print_to_file:
		{
			string path;
			cout << "Введите имя файла: ";
			cin >> path;
			ofstream fout(path);
			fout << collection;
			fout.close();
			break;
		}

		case nas_punkti:
		{
			cout << "Общее количество уникальных мест: " << collection.CountUniquePlaces() << endl;
			break;
		}

		case perevoz_obiem_diapazon:
		{
			cout << "Напишите интервал диапазона (мин/макс): ";
			int startV, endV;
			cin >> startV >> endV;
			TransportCompany collectionSortedByVolume = collection.getCollectionByVolumeRange(startV, endV);
			cout << collectionSortedByVolume;
			break;
		}

		case vivod_harac:
		{
			collection.print(cout);
		}

		case exit_program:
		{
			break;
		}
		}
	} while (ans != exit_program);
	return 0;
}

