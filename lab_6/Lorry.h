#pragma once
#include "CargoVehicle.h"

class Lorry : public CargoVehicle
{
protected:
	int anyAttributeS;

public:
	Lorry() : anyAttributeS(0) {}

	Lorry(std::string name_, int volume_, std::string way_from_, std::string way_to_, int anyAttributeS_)
		: CargoVehicle(name_, volume_, way_from_, way_to_), anyAttributeS(anyAttributeS_) {}

	Lorry(const Lorry& obj)
	{
		anyAttributeS = obj.anyAttributeS;
	}

	void print(std::ostream& out) const override;
	void scan(std::istream& in) override;
	CargoVehicle* getCopy() const override;
	std::string myName() const override;

};
