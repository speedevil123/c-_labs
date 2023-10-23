#include "CargoVehicle.h"
#include <fstream>
#include <iostream>

void CargoVehicle::print(std::ostream& out) const
{
	out << "��������: " << name << "\t" << "�����: " << volume << "\t" << "���� ������: " << way_from << "\t" << "���� ����: " << way_to;
}

void CargoVehicle::scan(std::istream& in)
{
	if (&in == &std::cin)
		std::cout << "������� ��������, �����, ���� ������/����: " << std::endl;
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
	return "�������� ���������";
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