#pragma once
#include "CargoVehicle.h"
#include <fstream>
#include <iostream>

class Ship : public CargoVehicle
{
protected:
	int anyAttributeB;

public:
	Ship() : anyAttributeB(0) {}
	Ship(std::string name_, int volume_, std::string way_from_, std::string way_to_, int anyAttributeB_)
		: CargoVehicle(name_, volume_, way_from_, way_to_), anyAttributeB(anyAttributeB_) {}

	Ship(const Ship& obj)
	{
		anyAttributeB = obj.anyAttributeB;
	}

	void print(std::ostream&) const override;
	void scan(std::istream&) override;

	CargoVehicle* getCopy() const override;
	std::string myName() const override;
};
