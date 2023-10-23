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
		cout << "�������� ����� ����: " << endl;
		cout << scan_from_keyboard << " - ������ � ����������" << endl
			<< scan_from_file << " - ������ �� �����" << endl
			<< print_to_display << " - ����� �� �����" << endl
			<< print_to_file << " - ����� � ����" << endl
			<< nas_punkti << " - ����� ���������� ���������� �������" << endl
			<< perevoz_obiem_diapazon << " - ����������� �������� ��������, � ������� ����� ������������� ���������� ���������" << endl
			<< vivod_harac << " - ����� ������������� ������� �������" << endl
			<< exit_program << " - �����" << endl;
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
			cout << "������� ��� �����: ";
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
			cout << "������� ��� �����: ";
			cin >> path;
			ofstream fout(path);
			fout << collection;
			fout.close();
			break;
		}

		case nas_punkti:
		{
			cout << "����� ���������� ���������� ����: " << collection.CountUniquePlaces() << endl;
			break;
		}

		case perevoz_obiem_diapazon:
		{
			cout << "�������� �������� ��������� (���/����): ";
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

