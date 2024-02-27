#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <fstream>

using namespace std;

class Vector
{
private:
	vector<pair<int, int>> coords;

public:
	Vector() {}
	Vector(vector<pair<int, int>> coords) : coords(coords) {}
	Vector(const Vector& other) : coords(other.coords) {}

	std::ostream& print(std::ostream& out) const
	{
		for (int i = 0; i < coords.size(); i++)
			out << coords[i].first << " " << coords[i].second << endl;
		return out;
	}

	std::istream& scan(std::istream& in)
	{
		int x, y;
		this->coords.clear();
		while (in >> x >> y)
		{
			coords.push_back(make_pair(x, y));
		}
		return in;
	}

	std::pair<double, double> computeMinMaxLen() const
	{
		double minLen = std::numeric_limits<double>::max();
		double maxLen = std::numeric_limits<double>::min();

		for (const auto& coord : coords)
		{
			double len = std::sqrt(coord.first * coord.first + coord.second * coord.second);

			if (len > maxLen)
			{
				maxLen = len;
			}
			if (len < minLen)
			{
				minLen = len;
			}
		}

		return { minLen, maxLen };
	}

	friend Vector operator + (const Vector& v1, const Vector& v2);
	friend Vector operator - (const Vector& v1, const Vector& v2);
	friend int operator * (const Vector& v1, const Vector& v2);
	friend Vector operator * (const Vector& v1,int scalar);
};

Vector operator + (const Vector& v1, const Vector& v2)
{
	if (v1.coords.size() != v2.coords.size())
	{
		throw invalid_argument("Vectors must be the same size");
	}
	vector<pair<int, int>> sum;
	for (int i = 0; i < v1.coords.size(); i++)
	{
		sum.push_back(make_pair(v1.coords[i].first + v2.coords[i].first, v1.coords[i].second + v2.coords[i].second));
	}
	return Vector(sum);
}

Vector operator - (const Vector& v1, const Vector& v2)
{
	if (v1.coords.size() != v2.coords.size())
	{
		throw invalid_argument("Vectors must be the same size");
	}
	vector<pair<int, int>> diff;
	for (int i = 0; i < v1.coords.size(); i++)
	{
		diff.push_back(make_pair(v1.coords[i].first - v2.coords[i].first, v1.coords[i].second - v2.coords[i].second));
	}
	return Vector(diff);
}

int operator * (const Vector& v1, const Vector& v2) {
	if (v1.coords.size() != v2.coords.size()) {
		return 0;
	}

	int result = 0;
	for (size_t i = 0; i < v1.coords.size(); i++) {
		result += v1.coords[i].first * v2.coords[i].first +
			v1.coords[i].second * v2.coords[i].second;
	}

	return result;
}

Vector operator * (const Vector& v1,int scalar)
{
	vector<pair<int, int>> prod;
	for (int i = 0; i < v1.coords.size(); i++)
	{
		prod.push_back(make_pair(v1.coords[i].first * scalar, v1.coords[i].second * scalar));
	}
	return Vector(prod);
}


