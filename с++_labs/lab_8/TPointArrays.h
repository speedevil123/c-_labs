#pragma once

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include "T3DPoint.h"
#include "TPointArrays_errors.h"

template <typename T>
double abs(const T& value)
{
    if constexpr (std::is_same<T, T3DPoint>::value)
    {
        return value.abs();
    }
    else
    {
        return std::abs(value);
    }
}


template<class T>
class TPointsArrays
{
private:
    T* arr1;
    T* arr2;
    int size1;
    int size2;

public:
    TPointsArrays()
    {
        arr1 = nullptr;
        arr2 = nullptr;
        size1 = 0;
        size2 = 0;
    }

    TPointsArrays(int s1, int s2)
    {
        arr1 = new T[s1];
        arr2 = new T[s2];
        size1 = s1;
        size2 = s2;
    }

    TPointsArrays(const TPointsArrays& other)
    {
        arr1 = new T[other.size1];
        arr2 = new T[other.size2];
        size1 = other.size1;
        size2 = other.size2;
        for (int i = 0; i < size1; i++) {
            arr1[i] = other.arr1[i];
        }
        for (int i = 0; i < size2; i++)
        {
            arr2[i] = other.arr2[i];
        }
    }


    TPointsArrays& operator=(TPointsArrays other)
    {
        std::swap(arr1, other.arr1);
        std::swap(arr2, other.arr2);
        std::swap(size1, other.size1);
        std::swap(size2, other.size2);
        return *this;
    }

    ~TPointsArrays()
    {
        delete[] arr1;
        delete[] arr2;
    }

    T* get_arr1() const { return arr1; }
    T* get_arr2() const { return arr2; }
    int get_size1() const { return size1; }
    int get_size2() const { return size2; }

    std::ostream& print(std::ostream& out) const
    {

        if (&out == &std::cout)
        {
            std::cout << "Введите X для массива типа int: " << std::endl;
        }

        for (size_t i = 0; i < size1; i++)
        {
            out << arr1[i] << std::endl;
        }

        if (&out == &std::cout)
        {
            std::cout << "Введите X для массива типа T3DPoint: " << std::endl;
        }

        for (size_t i = 0; i < size2; i++)
        {
            out << arr2[i] << std::endl;
        }

        return out;
    }

    std::istream& scan(std::istream& in)
    {
        if (&in == &std::cin)
        {
            std::cout << "Введите размеры двух массивов через пробел: " << std::endl;
        }
        in >> size1 >> size2;
        delete[] arr1;
        delete[] arr2;
        arr1 = new T[size1];
        arr2 = new T[size2];

        if (&in == &std::cin)
        {
            std::cout << "Введите элементы первого массива: " << std::endl;
        }

        for (size_t i = 0; i < size1; i++)
        {
            while (!(in >> arr1[i]))
            {
                std::cerr << "Ошибка: необходимо ввести число." << std::endl;
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            if (arr1[i] == 0)
            {
                throw TCenterCoordinate(i);
                break;
            }
            if (arr1[i] < T3DPoint::GetMin_val() || arr1[i] > T3DPoint::GetMax_val())
            {
                throw TCoordinateOutOfRange(i);
                break;
            }
        }

        if (&in == &std::cin)
        {
            std::cout << "Введите элементы второго массива: " << std::endl;
        }

        for (size_t i = 0; i < size2; i++)
        {
            while (!(in >> arr2[i]))
            {
                throw std::runtime_error("Ошибка: необходимо ввести число.");
                std::cerr << "Ошибка: необходимо ввести число." << std::endl;
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            if (arr2[i] == 0)
            {
                throw TCenterCoordinate(i);
                break;
            }
            if (arr2[i] < T3DPoint::GetMin_val() || arr2[i] > T3DPoint::GetMax_val())
            {
                throw TCoordinateOutOfRange(i);
                break;
            }
        }
        return in;
    }

    void max_points_within_distance(double X)
    {
        T sum_1 = arr1[0];
        T sum_2 = arr2[0];
        for (int i = 1; i < size1; i++)
        {
            sum_1 = sum_1 + arr1[i];
        }

        for (int i = 1; i < size2; i++)
        {
            sum_2 = sum_2 + arr2[i];
        }

        T middle1 = sum_1 / size1;
        T middle2 = sum_2 / size2;

        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < size1; i++)
        {
            if (abs(arr1[i] - middle1) <= X)
            {
                count1++;
            }
        }

        for (int i = 0; i < size2; i++)
        {
            if (abs(arr2[i] - middle2) <= X)
            {
                count2++;
            }
        }

        if (count1 > count2)
        {
            std::cout << "Первый массив удовлетворяет условию" << std::endl;
        }

        else if (count1 < count2)
        {
            std::cout << "Второй массив удовлетворет условию" << std::endl;
        }

        else
        {
            std::cout << "Оба массива удовлетворяют условию" << std::endl;
        }
        return;
    }

    void maxDistPairs()
    {
        T** pairs = new T * [std::min(size1, size2)];                       
        int pairCount = 0;     
        double maxDist = -1;

        for (int i = 0; i < std::min(size1, size2); i++)
        {
            double dist = abs(arr1[i] - arr2[i]);

            if (dist == maxDist)
            {
                pairs[pairCount++] = new T[2]{ arr1[i], arr2[i] };
            }
            else if (dist > maxDist)
            {
                maxDist = dist;
                pairCount = 0;
                pairs[pairCount++] = new T[2]{ arr1[i], arr2[i] };
            }
        }

        for (int i = 0; i < pairCount; i++)
        {
            std::cout << "(" << pairs[i][0] << "," << pairs[i][1] << ") ";
            delete[] pairs[i];
        }
        delete[] pairs;
    }

    T& operator[] (int index)
    {
        if (index < 0 || size1 <= index || size2 <= index)
            throw TIndexOutOfRange(index, "В операторе: T & operator [] (int index)\n");
        if (index < size1)
        {
            return arr1[index];
        }
        else
        {
            return arr2[index - size1];
        }
    }
};

template<typename T>
std::ostream& operator << (std::ostream& out, const TPointsArrays<T>& p)
{
    p.print(out);
    return out;
}

template<typename T>
std::istream& operator >> (std::istream& in, TPointsArrays<T>& p)
{
    p.scan(in);
    return in;
}
