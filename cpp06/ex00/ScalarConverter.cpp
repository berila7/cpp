/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student                                     #+#  #+#       #+#       */
/*                                                ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cctype>

/* ---- Orthodox Canonical Form (private) ---- */

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

/* ---- Helper: NaN / Inf detection (C++98 safe) ---- */

static bool ft_isnan(double v)
{
	return v != v;
}

static bool ft_isinf(double v)
{
	return !ft_isnan(v) && (v == std::numeric_limits<double>::infinity()
		|| v == -std::numeric_limits<double>::infinity());
}

static bool ft_isnanf(float v)
{
	return v != v;
}

static bool ft_isinff(float v)
{
	return !ft_isnanf(v) && (v == std::numeric_limits<float>::infinity()
		|| v == -std::numeric_limits<float>::infinity());
}

/* ---- Type enumeration ---- */

enum e_type
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
};

/* ---- Type detection ---- */

static e_type detectType(const std::string& literal)
{
	if (literal.empty())
		return TYPE_INVALID;

	/* Pseudo-literals */
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return TYPE_FLOAT;
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return TYPE_DOUBLE;

	/* Single printable non-digit char */
	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
		return TYPE_CHAR;

	/* Numeric analysis */
	bool hasF = (literal[literal.length() - 1] == 'f');
	bool hasDot = (literal.find('.') != std::string::npos);

	std::string numStr = hasF ? literal.substr(0, literal.length() - 1) : literal;

	if (numStr.empty())
		return TYPE_INVALID;

	std::size_t i = 0;
	if (numStr[0] == '+' || numStr[0] == '-')
		i++;

	if (i >= numStr.length())
		return TYPE_INVALID;

	bool foundDot = false;
	bool foundDigit = false;
	for (; i < numStr.length(); i++)
	{
		if (numStr[i] == '.')
		{
			if (foundDot)
				return TYPE_INVALID;
			foundDot = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(numStr[i])))
			foundDigit = true;
		else
			return TYPE_INVALID;
	}

	if (!foundDigit)
		return TYPE_INVALID;
	if (hasF && hasDot)
		return TYPE_FLOAT;
	if (hasF && !hasDot)
		return TYPE_INVALID;
	if (hasDot)
		return TYPE_DOUBLE;
	return TYPE_INT;
}

/* ---- Display helpers ---- */

static void displayChar(double value)
{
	if (ft_isnan(value) || ft_isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void displayInt(double value)
{
	if (ft_isnan(value) || ft_isinf(value)
		|| value > static_cast<double>(std::numeric_limits<int>::max())
		|| value < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void displayFloat(double value)
{
	float f = static_cast<float>(value);

	if (ft_isnanf(f))
	{
		std::cout << "float: nanf" << std::endl;
		return;
	}
	if (ft_isinff(f))
	{
		if (!ft_isinf(value))
		{
			std::cout << "float: impossible" << std::endl;
			return;
		}
		if (f > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
		return;
	}

	std::ostringstream oss;
	oss << f;
	std::string str = oss.str();
	if (str.find('.') == std::string::npos
		&& str.find('e') == std::string::npos
		&& str.find('E') == std::string::npos)
		str += ".0";
	std::cout << "float: " << str << "f" << std::endl;
}

static void displayDouble(double value)
{
	if (ft_isnan(value))
	{
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (ft_isinf(value))
	{
		if (value > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
		return;
	}

	std::ostringstream oss;
	oss << value;
	std::string str = oss.str();
	if (str.find('.') == std::string::npos
		&& str.find('e') == std::string::npos
		&& str.find('E') == std::string::npos)
		str += ".0";
	std::cout << "double: " << str << std::endl;
}

/* ---- Public static method ---- */

void ScalarConverter::convert(const std::string& literal)
{
	e_type type = detectType(literal);
	double value;

	switch (type)
	{
		case TYPE_CHAR:
			value = static_cast<double>(literal[0]);
			break;
		case TYPE_INT:
		{
			long l = std::strtol(literal.c_str(), NULL, 10);
			if (l > std::numeric_limits<int>::max()
				|| l < std::numeric_limits<int>::min())
			{
				/* Use strtod for larger-range display */
				value = std::strtod(literal.c_str(), NULL);
			}
			else
				value = static_cast<double>(l);
			break;
		}
		case TYPE_FLOAT:
		case TYPE_DOUBLE:
			value = std::strtod(literal.c_str(), NULL);
			break;
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
	}

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}
