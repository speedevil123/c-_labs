#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>

class TPointError : public std::exception
{
protected:
	std::string m_description = "Ошибка в шаблонном классе. \n";
public:
	TPointError() {}
	TPointError(const std::string& _error)
		: m_description(_error) {
		message();
	}

	void addLocation(const std::string& _where)
	{
		m_description += _where;
	}

	const char* what() const
	{
		return m_description.c_str();
	}

	void message() const
	{
		std::ofstream logFile("errors_log.txt", std::ios::app);
		logFile << m_description << std::endl;
		logFile.close();
	}

	virtual ~TPointError() {}
};

class TCoordinateOutOfRange : public TPointError
{
public:
	double coordinate_name;

	TCoordinateOutOfRange(const double& _coordinate_name) : TPointError("Error: Одна из координат точки выходит за установленные границы. \n"), coordinate_name(_coordinate_name)
	{}

	TCoordinateOutOfRange(const double& _coordinate_name, const std::string& _where) : TCoordinateOutOfRange(_coordinate_name)
	{
		addLocation(_where);
	}
};

class TWrongType : public TPointError
{
public:
	TWrongType()
		: TPointError("Error: Попытка ввести неверный тип данных. \n")
	{}
	TWrongType(const std::string& _where)
		: TWrongType()
	{
		addLocation(_where);
	}
};

class TIndexOutOfRange : public TPointError
{
public:
	int index;
	TIndexOutOfRange(int _index)
		: TPointError("Error: Индекс вне диапазона.\n")
		, index(_index)
	{}
	TIndexOutOfRange(int _index, const std::string& _where)
		: TIndexOutOfRange(_index)
	{
		addLocation(_where);
	}
};


class TCenterCoordinate : public TPointError
{
public:
	double coordinate_name;

	TCenterCoordinate(const double& _coordinate_name) : TPointError("Error: Одна из координат распологается в центре. \n"), coordinate_name(_coordinate_name)
	{}

	TCenterCoordinate(const double& _coordinate_name, const std::string& _where) : TCenterCoordinate(_coordinate_name)
	{
		addLocation(_where);
	}
};




