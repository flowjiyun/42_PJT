/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:09:30 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/27 14:23:41y jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isValidInput(std::string literal)
{
	int len;
	int cntPoint;

	len = literal.length();
	cntPoint = 0;
	if (len != 1)
	{
		if (len == 2)
		{
			if ((literal[0] == '+' || literal[0] == '-') && literal[1] == 'f')
				return (false);
		}
		if (!(literal[0] == '+' || literal[0] == '-') && !isdigit(literal[0]))
			return (false);
		for (int i = 1; i < len - 1; ++i)
		{
			if (!isdigit(literal[i]))
			{
				if (literal[i] == '.')
				{
					++cntPoint;
					if (cntPoint > 1)
						return (false);	
				}
				else
					return (false);
			}
		}
		if ((literal[len - 1] >= '0' && literal[len - 1] <= '9') || literal[len - 1] == 'f')
			return (true);
		else
			return (false);
	}
	else
		return (true);
}

static bool isFloatInfOrNan(const std::string literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	else
		return (false);
}

static bool isDoubleInfOrNan(const std::string literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	else
		return (false);
}

static bool isChar(const std::string literal)
{
	if (literal.length() == 1)
		return (true);
	return (false);
}

static bool isInt(const std::string literal)
{
	if (literal.find('.') == std::string::npos &&
		literal.find('f') == std::string::npos)
		return (true);
	return (false);
}

static bool isFloat(const std::string literal)
{
	if (literal.find('.') && literal.find('f'))
		return (true);
	return (false);
}

static int checkType(const std::string literal)
{
	if (isFloatInfOrNan(literal))
		return (FLOATINF);
	if (isDoubleInfOrNan(literal))
		return (DOUBLEINF);	
	if (!isValidInput(literal))
		return (ERROR);
	if (isChar(literal))
		return (CHAR);
	if (isInt(literal))
		return (INT);
	if (isFloat(literal))
		return (FLOAT);
	return (DOUBLE);
}

static void printChar(std::string literal)
{
	const std::string error = "impossible";
	int num;

	num = atoi(literal.c_str());
	// 문자가 출력가능한 ascii 문자인지 확인(0이면 출력 불가)
	if (isprint(*literal.c_str()))
	{
		if (num >= 1 && num <= 9)
			std::cout << "char: " << "Non displayable" << std::endl;
		else if (*literal.c_str() == '0')
			std::cout << "char: " << "Non displayable" << std::endl;
		else
			std::cout << "char: " << "'" << *literal.c_str() << "'" << std::endl;
	}
	if (isdigit(static_cast<int>(*literal.c_str())))
	{
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << std::showpoint << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << std::showpoint << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(num) << std::endl;
	}
	else
	{
		std::cout << "int: " << error << std::endl;
		std::cout << "float: " << error << std::endl;
		std::cout << "double: " << error << std::endl;
	}
}

static bool isValidInt(double numDouble)
{
	if (numDouble >= std::numeric_limits<int>::min() && numDouble <= std::numeric_limits<int>::max())
		return (true);
	else
		return (false);
}

static bool isValidFloat(double numDouble)
{
	if (numDouble >= -std::numeric_limits<float>::max() && numDouble <= std::numeric_limits<float>::max())
		return (true);
	else
		return (false);
}

static bool isValidDouble(double numDouble)
{
	if (numDouble >= -std::numeric_limits<double>::max() && numDouble <= std::numeric_limits<double>::max())
		return (true);
	else
		return (false);
}

static void printError(void)
{
	const std::string error = "impossible";

	std::cout << "char: " << error << std::endl;
	std::cout << "int: " << error << std::endl;
	std::cout << "float: " << error << std::endl;
	std::cout << "double: " << error << std::endl;
}

static void printNumErrorCheck(double numDouble, const std::string error)
{
	std::cout << "char: " << error << std::endl;
	if (isValidInt(numDouble))
		std::cout << "int: " << static_cast<int>(numDouble) << std::endl;
	else
		std::cout << "int: " << error << std::endl;
	if (isValidFloat(numDouble))
		std::cout << std::showpoint << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(numDouble) << "f" << std::endl;
	else
		std::cout << "float: " << error << std::endl;
	if (isValidDouble(numDouble))
		std::cout << std::showpoint << std::fixed << std::setprecision(1) << "double: " << numDouble << std::endl;
	else
		std::cout << "double: " << error << std::endl;
}

static void printIntToDouble(double numDouble , const std::string error)
{
	std::cout << "int: " << static_cast<int>(numDouble) << std::endl;
	if (isValidFloat(numDouble))
		std::cout << std::showpoint << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(numDouble) << "f" << std::endl;
	else
		std::cout << "float: " << error << std::endl;
	std::cout << std::showpoint << std::fixed << std::setprecision(1) << "double: " << numDouble << std::endl;
}

static void printNumber(std::string literal)
{
	const std::string error = "impossible";
	int numInt;
	double numDouble;

	numInt = atoi(literal.c_str());
	numDouble = strtod(literal.c_str(), NULL);
	if (isValidDouble(numDouble) && isValidInt(numDouble))
	{
		// .0으로 떨어지는 소수점 숫자를 문자로 변환하기 위해
		if (numDouble - numInt == 0)
		{
			if (numInt <= std::numeric_limits<char>::max() && numInt >= 0)
			{
				if (isprint(numInt))
					std::cout << "char: " << "'" << static_cast<char>(numInt) << "'" << std::endl;
				else
					std::cout << "char: " << "Non displayable" << std::endl;
			}
			else
				std::cout << "char: " << error << std::endl;
			printIntToDouble(numDouble, error);
		}
		else
		{
			std::cout << "char: " << error << std::endl;
			printIntToDouble(numDouble, error);
		}
	}
	else
		printNumErrorCheck(numDouble, error);
}

static void printInfOrNan(std::string literal, int type)
{
	const std::string error = "impossible";

	std::cout << "char: " << error << std::endl;
	std::cout << "int: " << error << std::endl;
	if (type == FLOATINF)
	{
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0,literal.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << literal + "f" << std::endl;
		std::cout << "double: " << literal<< std::endl;
	}
}

void ScarlarConverter::convert(std::string literal)
{
	int type;

	type = checkType(literal);
	if (type == ERROR)
		printError();
	else if (type == FLOATINF || type == DOUBLEINF)
		printInfOrNan(literal, type);
	else if (type == CHAR)
		printChar(literal);
	else
		printNumber(literal);
}