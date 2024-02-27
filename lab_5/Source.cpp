#include "Header.h"
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

Vector& Vector::operator = (const Vector& other)
{
	if (this != &other)
	{
		delete[] arr_;
		num_ = other.num_;
		arr_ = new double[num_];
		for (int i = 0; i < num_; i++)
		{
			arr_[i] = other.arr_[i];
		}
	}
	return *this;

}

double* Vector::getNumbers() const
{
	return arr_;
}

int Vector::getSize() const
{
	return num_;
}

Vector& Vector::GenerateValue(double min, double max, int num)
{
	if (arr_ != nullptr)
	{
		delete[] arr_;
		num_ = 0;
	}
	num_ = num;
	arr_ = new double[num_];

	for (int i = 0; i < num_; i++)
	{
		arr_[i] = sqrt((double)rand() / RAND_MAX) * (max - min) + min;
	}
	return *this;
}

double Vector::GetMax() const
{
	double max = arr_[0];
	for (int i = 0; i < num_; i++)
	{
		if (arr_[i] > max)
		{
			max = arr_[i];
		}
	}
	return max;
}

double Vector::GetMin() const
{
	double min = arr_[0];
	for (int i = 0; i < num_; i++)
	{
		if (arr_[i] < min)
		{
			min = arr_[i];
		}
	}
	return min;
}

double& Vector::operator[](int index)
{
	return arr_[index];
}

ostream& Vector::print(ostream& stream) const
{
	for (int i = 0; i < num_; i++)
	{
		stream << " " << setw(6) << setprecision(3) << arr_[i];
	}
	return stream;
}

istream& Vector::scan(istream& stream)
{
	if (arr_ != nullptr)
	{
		delete[] arr_;
		num_ = 0;
	}

	if (&stream == &cin)
	{
		cout << "¬ведите размер и элементы вектора чисел: ";
	}
	stream >> num_;
	arr_ = new double[num_];
	for (int i = 0; i < num_; i++)
	{
		stream >> arr_[i];
	}

	return stream;
}

Vector operator + (const Vector& first, const Vector& second)
{
	Vector ans;
	ans.num_ = first.num_;
	ans.arr_ = new double[ans.num_];

	for (int i = 0; i < ans.num_; i++)
	{
		ans[i] = first.arr_[i] + second.arr_[i];
	}
	return ans;
}

Vector operator - (const Vector& first, const Vector& second)
{
	Vector ans;
	ans.num_ = first.num_;
	ans.arr_ = new double[ans.num_];

	for (int i = 0; i < ans.num_; i++)
	{
		ans[i] = first.arr_[i] - second.arr_[i];
	}
	return ans;
}

Vector operator * (const Vector& first, const Vector& second)
{
	Vector ans;
	ans.num_ = first.num_;
	ans.arr_ = new double[ans.num_];

	for (int i = 0; i < ans.num_; i++)
	{
		ans[i] = first.arr_[i] * second.arr_[i];
	}
	return ans;
}

std::ostream& operator << (std::ostream& stream, const Vector& obj)
{
	return obj.print(stream);
}

std::istream& operator >> (std::istream& stream, Vector& obj)
{
	return obj.scan(stream);
}

Vector* sort_mas(Vector* arr, int size)
{
	double* average = new double[size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (average[j] > average[j + 1])
			{
				double temp = average[j];
				Vector temp1 = arr[j];
				average[j] = average[j + 1];
				arr[j] = arr[j + 1];
				average[j + 1] = temp;
				arr[j + 1] = temp1;
			}
		}
	}
	return arr;
}