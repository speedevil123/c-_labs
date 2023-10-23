#pragma once
#include "CargoVehicle.h"

class TransportCompany
{
private:
	CargoVehicle** arr;
	unsigned int size;

public: 
	TransportCompany(CargoVehicle** arr = nullptr, unsigned int size_ = 0);
	TransportCompany(TransportCompany&& p);

	void clearMemory();

	TransportCompany getCollectionByVolumeRange(int startV, int endV);

	void print(std::ostream& out) const;
	void scan(std::istream& in);

	~TransportCompany()
	{
		clearMemory();
	}

	int CountUniquePlaces();
};

std::istream& operator >> (std::istream& in, TransportCompany& obj);
std::ostream& operator << (std::ostream& out, const TransportCompany& obj);