#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Vector
{
private:
	double* arr_;
	int num_;

public:
	Vector()
	{
		num_ = 0;
		arr_ = nullptr;
	}

	Vector(double* arr, int num)
	{
		num_ = num;
		arr_ = new double[num_];

		for (int i = 0; i < num_; i++)
		{
			arr_[i] = arr[i];
		}
	}

	Vector(const Vector& other)
	{
		arr_ = new double[other.num_];
		for (int i = 0; i < other.num_; i++)
		{
			arr_[i] = other.arr_[i];
		}
		num_ = other.num_;
	}

	Vector& operator = (const Vector& other);

	double* getNumbers() const;
	int getSize() const;
	~Vector() { delete[] arr_; }
	Vector& GenerateValue(double min, double max, int num);
	double GetMax() const;
	double GetMin() const;
	double& operator [] (int index);

	std::ostream& print(std::ostream& stream) const;
	std::istream& scan(std::istream& stream);

	friend Vector operator + (const Vector& first, const Vector& second);
	friend Vector operator - (const Vector& first, const Vector& second); 
	friend Vector operator * (const Vector& first, const Vector& second);
};

Vector* sort_mas(Vector* arr, int size);
std::ostream& operator << (std::ostream& stream, const Vector& obj);
std::istream& operator >> (std::istream& stream, Vector& obj);
