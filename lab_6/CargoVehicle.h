#pragma once
#include <fstream>
#include <iostream>

class CargoVehicle
{
protected:
	std::string name;
	int volume;
	std::string way_from;
	std::string way_to;
public:
	CargoVehicle() : name(""), volume(0), way_from(""), way_to("") {}
	CargoVehicle(std::string name_, int volume_, std::string way_from_, std::string way_to_) : name(name_), volume(volume_), way_from(way_from_), way_to(way_to_) {}

	virtual void print(std::ostream& out) const;
	virtual void scan(std::istream& in);

	virtual std::string myName() const;
	int getVolume() { return volume; }
	std::string getWay_From() { return way_from; }
	std::string getWay_To() { return way_to; }
	std::string getName() { return name; }
	bool checkVolumeRange(int startV, int endV) const;

	virtual CargoVehicle* getCopy() const = 0;
	virtual ~CargoVehicle() {}
};

std::ostream& operator << (std::ostream& out, const CargoVehicle& s);
std::istream& operator >> (std::istream& in, CargoVehicle& s);