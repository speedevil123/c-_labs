#include "Header.h"
#include <fstream>
#include <iostream>

using namespace std;

Service scan(istream& in)
{
	Service p;
	if (&in == &cin)
	{
		cout << "Введите услугу: ";
	}
	in >> p.name_of_service;

	if (&in == &cin)
	{
		cout << "Введите тип работ: ";
	}
	in >> p.type_of_work;

	if (&in == &cin)
	{
		cout << "Введите стоимость услуги: ";
	}
	in >> p.cost;

	if (&in == &cin)
	{
		cout << "Введите длительность работ: ";
	}
	in >> p.deadline;
	return p;
}

Service* scan(istream& in, int& num)
{
	if (&in == &cin)
		cout << "Введите количество услуг: ";
	in >> num;
	Service* arr = new Service[num];
	for (int i = 0; i < num; i++)
	{
		arr[i] = scan(in);
	}
	return arr;
}

void print(ostream& out, const Service& p)
{
	out << p.name_of_service << endl;
	out << p.type_of_work << endl;
	out << p.deadline << endl;
	out << p.cost << endl;
}

void print(ostream& out, const Service* p, int num)
{
	out << num << endl;
	for (int i = 0; i < num; i++)
	{
		print(out, p[i]);
		out << endl;
	}
}

Service* finder(Service* p, string yslyga, int num, int& num2)
{
	Service* arr = new Service[num];
	int h = 0;
	for (int i = 0; i < num; i++)
	{
		if (yslyga == p[i].name_of_service)
		{
			arr[h].name_of_service = p[i].name_of_service;
			arr[h].type_of_work = p[i].type_of_work;
			arr[h].cost = p[i].cost;
			arr[h++].deadline = p[i].deadline;
			/*arr[h++] = p[i];*/
		}
	}
	num2 = h;

	return arr;
}

float Ratio(const Service& sv)
{
	return sv.cost / sv.deadline;
}

bool Compare(const Service& sv1, const Service& sv2) { return Ratio(sv1) > Ratio(sv2); }
