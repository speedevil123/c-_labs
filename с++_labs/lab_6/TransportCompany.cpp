#include "TransportCompany.h"
#include "Ship.h"
#include "Lorry.h"
#include <vector>
#include <unordered_set>

TransportCompany::TransportCompany(CargoVehicle** arr_, unsigned int size_)
{
	size = size_;
	if (arr_ != nullptr)
	{
		arr = new CargoVehicle * [size];
		for (unsigned int i = 0; i < size; i++)
		{
			arr[i] = (*arr_[i]).getCopy();
		}
	}
	else
		arr = arr_;
}

TransportCompany::TransportCompany(TransportCompany&& p)
{
	std::swap(arr, p.arr);
	std::swap(size, p.size);
}

void TransportCompany::print(std::ostream& out) const
{
	out << size << "\n";
	for (unsigned int i = 0; i < size; i++)
	{
		out << (*arr[i]) << "\n";
	}
}

void TransportCompany::scan(std::istream& in)
{
	if (&in == &std::cin)
		std::cout << "Задайте размер коллекции транспорта: ";
	unsigned int sizeN;
	in >> sizeN;
	CargoVehicle** arrs = new CargoVehicle * [sizeN];
	for (unsigned int i = 0; i < sizeN; i++)
	{
		if (&in == &std::cin)
			std::cout << "Напишите тип транспорта (Lorry/Ship): " << std::endl;
		std::string type;
		in >> type;
		if (type == "Lorry")
			arrs[i] = new Lorry;
		else if (type == "Ship")
			arrs[i] = new Ship;
		in >> (*arrs[i]);
	}

	clearMemory();
	arr = arrs;
	size = sizeN;
}

int TransportCompany::CountUniquePlaces()
{
	std::vector<std::string> uniqueArr;
	int UniqueTo = 0;
	int UniqueFrom = 0;

	for (int i = 0; i < size; i++)
	{
		bool isUniqueTo = true;
		bool isUniqueFrom = true;
		for (int j = 0; j < i; j++)
		{
			if ((*arr[i]).getWay_To() == (*arr[j]).getWay_To())
			{
				isUniqueTo = false;
				break;
			}

			if ((*arr[i]).getWay_From() == (*arr[j]).getWay_From())
			{
				isUniqueTo = false;
				break;
			}
		}
		if (isUniqueTo)
		{
			uniqueArr.push_back((*arr[i]).getWay_To());
			UniqueTo++;
		}
		if (isUniqueFrom)
		{
			uniqueArr.push_back((*arr[i]).getWay_From());
			UniqueFrom++;
		}
	}

	std::unordered_set<std::string> uniquesetto;
	for (int i = 0; i < uniqueArr.size(); i++)
		uniquesetto.insert(uniqueArr[i]).second;

	std::cout << "Количество уникальных мест отправления: " << UniqueFrom << std::endl;
	std::cout << "Количество уникальных мест назначения: " << UniqueTo << std::endl;

	return uniquesetto.size();
}

void TransportCompany::clearMemory()
{
	for (unsigned int i = 0; i < size; i++)
		delete arr[i];

	delete[] arr;
	arr = nullptr;
	size = 0;

}

TransportCompany TransportCompany::getCollectionByVolumeRange(int startV, int endV)
{
	unsigned int sizeN = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		if ((*arr[i]).checkVolumeRange(startV, endV))
			sizeN++;
	}

	CargoVehicle** arrN = new CargoVehicle * [sizeN + 1];
	for (unsigned int j = 0, k = 0; j < size; j++)
		if ((*arr[j]).checkVolumeRange(startV, endV))
		{
			arrN[k] = arr[j];
			k++;
		}
	TransportCompany collectionN(arrN, sizeN);
	return collectionN;
}

std::istream& operator >> (std::istream& in, TransportCompany& obj)
{
	obj.scan(in);
	return in;
}

std::ostream& operator << (std::ostream& out, const TransportCompany& obj)
{
	obj.print(out);
	return out;
}