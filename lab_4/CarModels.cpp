#include "CarModels.h"
#include <fstream>
#include <iostream>

using namespace std;

CarModels::CarModels()
{
	name_ = "";
	year_ = 0;
	color_ = "";
	maxSpeed_ = 0;
	bodyType_ = "";
	price_ = 0;
}
CarModels::CarModels(string name, int year, string color, int maxSpeed, int price)
{
	name_ = name;
	year_ = year;
	color_ = color;
	maxSpeed_ = maxSpeed;
	price_ = price;
}
CarModels::CarModels(const CarModels& _other)
	: CarModels(_other.name_, _other.year_, _other.color_, _other.maxSpeed_, _other.price_)    /*присваиваем значения параметрам засчет операторов доступа*/
{}

void CarModels::print(ostream& out)
{
	out << name_ << " " << year_ << " " << color_ << " " << maxSpeed_ << " " << bodyType_ << " " << price_;
}

CarModels& CarModels::scan(istream& in)
{
	if (&in == &cin)
		cout << "Введите модель, год выпуска, цвет, макс. скорость, тип кузова, цену: " << endl;
	in >> name_ >> color_ >> bodyType_ >> year_ >> maxSpeed_ >> price_;
	return *this;
}

bool CarModels::colorAndYearCheck(string color, int year)
{
	return (color_ == color && year_ > year);
}

bool CarModelsArray::proverka1(int carindex, string color, int year)
{
	return p[carindex - 1].colorAndYearCheck(color, year);
}

bool CarModelsArray::proverka2(int carindex, string kuzov)
{
	return p[carindex - 1].bodyTypeCheck(kuzov);
}

bool CarModelsArray::proverka3(int carindex, int minspeed, int maxspeed)
{
	return p[carindex - 1].maxSpeedCheck(minspeed, maxspeed);
}

bool CarModels::bodyTypeCheck(string bodyType)
{
	return bodyType_ == bodyType;
}

bool CarModels::maxSpeedCheck(int minSpeed, int maxSpeed)
{
	return(maxSpeed_ >= minSpeed && maxSpeed_ <= maxSpeed);
}

void CarModelsArray::print(std::ostream& out)
{
	out << num << endl;
	for (int i = 0; i < num; i++)
	{
		if (&out == &cout)
		{
			cout << "Номер автомобиля: " << i + 1 << endl;
		}
		p[i].print(out);
		out << endl;
	}
}

CarModelsArray& CarModelsArray::scan(std::istream& in)
{
	if (&in == &cin)
		cout << "Введите количество моделей: ";
	in >> num;
	CarModels* arr = new CarModels[num];
	for (int i = 0; i < num; i++)
	{
		arr[i].scan(in);
	}
	delete[] p;
	p = arr;
	return *this;
}

CarModelsArray CarModelsArray::printColorAndYear(std::string color, int year)
{
	int Size = 0;
	for (int i = 0; i < num; i++) {
		if (p[i].colorAndYearCheck(color, year))
		{
			Size++;
		}
	}
	CarModels* Arr = new CarModels[Size];
	int h = 0;
	for (int i = 0; i < num; i++)
	{
		if (p[i].colorAndYearCheck(color, year))
		{
			Arr[h++] = p[i];
		}
	}
	return CarModelsArray(Arr, Size);
}

CarModelsArray CarModelsArray::printBodyType(string kuzov)
{
	int Size = 0;
	for (int i = 0; i < num; i++) {
		if (p[i].bodyTypeCheck(kuzov))
		{
			Size++;
		}
	}
	CarModels* Arr = new CarModels[Size];
	int Index = 0;
	for (int i = 0; i < num; i++)
	{
		if (p[i].bodyTypeCheck(kuzov))
		{
			Arr[Index++] = p[i];
		}
	}
	return CarModelsArray(Arr, Size);
}

CarModelsArray CarModelsArray::printMaxSpeed(int minSpeed, int maxSpeed)
{
	int Size = 0;
	for (int i = 0; i < num; i++) {
		if (p[i].maxSpeedCheck(minSpeed, maxSpeed))
		{
			Size++;
		}
	}
	CarModels* Arr = new CarModels[Size];
	int Index = 0;
	for (int i = 0; i < num; i++)
	{
		if (p[i].maxSpeedCheck(minSpeed, maxSpeed))
		{
			Arr[Index++] = p[i];
		}
	}
	return CarModelsArray(Arr, Size);
}