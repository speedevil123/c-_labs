#include <iostream>
#include <cstdlib>
#include <cmath>
#include "TPointArrays_errors.h"
#include "T3DPoint.h"
#include "TPointArrays.h"

using namespace std;


int main()
{
	system("chcp 1251");
	TPointsArrays<T3DPoint> arr_points;
	TPointsArrays<int> arr_int;
	
	while (true)
	{
		try
		{
			cin >> arr_int;
			cin >> arr_points;
			break;
		}

		catch (TPointError& e)
		{
			cout << e.what() << std::endl;
			std::ofstream fout("error_log.txt", std::ios::out | std::ios::app);
			fout << e.what() << std::endl;
			fout.close();
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << "Ошибка: необходимо ввести число." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::ofstream fout("error_log.txt", std::ios::out | std::ios::app);
			fout << "std::runtime_error: " << e.what() << std::endl;
			fout.close();
		}
	}
	arr_points.print(cout);
	arr_int.print(cout);
}