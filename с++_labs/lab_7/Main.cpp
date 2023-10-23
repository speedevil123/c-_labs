#include "T3DPoint.h"
#include "TPointArrays.h"
#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251");
	TPointsArrays<int> arr_int;
	TPointsArrays<T3DPoint> arr_points;

	cin >> arr_int;
	cin >> arr_points;

	cout << "¬ведите X дл€ массива типа int: " << endl;
	double X1;
	cin >> X1;

	cout << "¬ведите X дл€ массива T3DPoint: " << endl;
	double X2;
	cin >> X2;

	arr_int.max_points_within_distance(X1);
	arr_points.max_points_within_distance(X2);
}