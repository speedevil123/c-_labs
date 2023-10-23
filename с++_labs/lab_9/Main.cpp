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
		cout << "�������� ����� ����: " << endl
			<< scan_from_file << " - ������ �� �����" << endl
			<< print_to_file << " - ����� � ����" << endl
			<< min_max_length << " - ����������� ���. � ����. �� ����� ��������" << endl
			<< exit_program << " - ����� �� ���������" << endl;
		cin >> ans;
		
		switch (ans)
		{
		case scan_from_file:
		{
			string path;
			cout << "������� �������� �����: " << endl;
			cin >> path;
			ifstream fin(path + ".txt");
			p.scan(fin);
			fin.close();
			break;
		}

		case print_to_file:
		{
			string path;
			cout << "������� �������� �����: " << endl;
			cin >> path;
			ofstream fout(path + ".txt");
			p.print(fout);
			fout.close();
			break;
		}

		case min_max_length:
		{
			std::pair<double, double> max_min = p.computeMinMaxLen();
			cout << "����������� ������: " << max_min.first << "������������ ������: " << max_min.second << endl;
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