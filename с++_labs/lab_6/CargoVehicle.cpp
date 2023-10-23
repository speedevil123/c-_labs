#include "CargoVehicle.h"
#include <fstream>
#include <iostream>

void CargoVehicle::print(std::ostream& out) const
{
	out << "Название: " << name << "\t" << "Объем: " << volume << "\t" << "Путь откуда: " << way_from << "\t" << "Путь куда: " << way_to;
}

void CargoVehicle::scan(std::istream& in)
{
	if (&in == &std::cin)
		std::cout << "Введите название, объем, путь откуда/куда: " << std::endl;
	in >> name >> volume >> way_from >> way_to;
}

bool CargoVehicle::checkVolumeRange(int startV, int endV) const
{
	if ((startV <= volume) && (volume <= endV))
		return true;
	return false;
}

std::string CargoVehicle::myName() const
{
	return "Грузовой транспорт";
}

std::ostream& operator << (std::ostream& out, const CargoVehicle& s)
{
	s.print(out);
	return out;
}

std::istream& operator >> (std::istream& in, CargoVehicle& s)
{
	s.scan(in);
	return in;
}