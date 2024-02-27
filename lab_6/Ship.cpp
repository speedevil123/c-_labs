#include "Ship.h"

void Ship::print(std::ostream& out) const
{
	CargoVehicle::print(out);
	out << "\t" << "AttributeB: " << anyAttributeB;

}

void Ship::scan(std::istream& in)
{
	CargoVehicle::scan(in);
	if (&in == &std::cin)
		std::cout << "Напишите уточняющую характеристику: ";
	in >> anyAttributeB;
}

CargoVehicle* Ship::getCopy() const
{
	return new Ship(name, volume, way_from, way_to, anyAttributeB);
}

std::string Ship::myName() const
{
	return "Ship";
}
