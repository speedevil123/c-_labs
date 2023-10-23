#pragma once
#include <iostream>
#include <string>
#include <fstream>

class CarModels
{
	std::string name_;
	std::string color_;
	std::string bodyType_;
	int year_;
	int maxSpeed_;
	int price_;
public:
	CarModels();                              /*конструктор по умолчанию*/
	CarModels& scan(std::istream& in);
	CarModels(const CarModels& _other);        /*конструктор копирования*/
	CarModels(std::string name, int year, std::string color, int maxSpeed, int price);     /*конструктор с параметрами ( присваивать значение )*/
	void print(std::ostream& out);
	bool colorAndYearCheck(std::string color, int year);
	bool bodyTypeCheck(std::string bodyType);                             /*3 булевых для проверок*/
	bool maxSpeedCheck(int minSpeed, int maxSpeed);
};
class CarModelsArray
{
	CarModels* p;
	int num;
public:
	CarModelsArray() : p(nullptr), num(0) {}
	CarModelsArray(CarModels* ptr, int n)
	{
		p = ptr;
		num = n;
	}
	CarModelsArray(const CarModelsArray& other)
	{
		num = other.num;
		CarModels* p = new CarModels[num];
		for (int i = 0; i < num; i++)
		{
			p[i] = other.p[i];
		}
	}
	~CarModelsArray() { delete[]p; }
	void print(std::ostream& out);
	CarModelsArray& scan(std::istream& in);
	CarModelsArray printMaxSpeed(int minSpeed, int maxSpeed);
	CarModelsArray printColorAndYear(std::string color, int year);           /*3 выборок*/
	CarModelsArray printBodyType(std::string kuzov);
	bool proverka1(int carindex, std::string color, int year);
	bool proverka2(int carindex, std::string kuzov);                      /*3 проверки*/
	bool proverka3(int carindex, int minspeed, int maxspeed);

};
