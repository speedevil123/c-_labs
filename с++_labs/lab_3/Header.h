#pragma once
#include <string>

struct Service
{
	std::string name_of_service;
	std::string type_of_work;
	float cost;
	float deadline;
};

Service* scan(std::istream& in, int& num);
void print(std::ostream& out, const Service* p, int num);
float Ratio(const Service& cr);
bool Compare(const Service& sv1, const Service& sv2);
Service* finder(Service* p, std::string yslyga, int num, int& num2);
