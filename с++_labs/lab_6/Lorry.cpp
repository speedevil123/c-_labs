#include "Lorry.h"

void Lorry::print(std::ostream& out) const
{
	CargoVehicle::print(out);
	out << "\t" << "AttributeS: " << anyAttributeS;
}

void Lorry::scan(std::istream& in)
{
	CargoVehicle::scan(in);
	if (&in == &std::cin)
		std::cout << "Напишите уточняющую характеристику: ";
	in >> anyAttributeS;
}

CargoVehicle* Lorry::getCopy() const
{
	return new Lorry(name, volume, way_from, way_to, anyAttributeS);
}

std::string Lorry::myName() const
{
	return "Lorry";
}
