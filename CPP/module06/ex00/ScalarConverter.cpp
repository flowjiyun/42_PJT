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

bool isValidInput(std::string literal)
{
	int len;
	int cntPoit;

	len = literal.length();
	cntPoit = 0;
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
					++cntPoit;
					if (cntPoit > 1)
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

bool isFloatInfOrNan(const std::string literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	else
		return (false);
}

bool isDoubleInfOrNan(const std::string literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	else
		return (false);
}

bool isChar(const std::string literal)
{
	if (literal.length() == 1)
		return (true);
	return (false);
}

bool isInt(const std::string literal)
{
	if (literal.find('.') == std::string::npos &&
		literal.find('f') == std::string::npos)
		return (true);
	return (false);
}

bool isFloat(const std::string literal)
{
	if (literal.find('.') && literal.find('f'))
		return (true);
	return (false);
}

int checkType(const std::string literal)
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

void printChar(std::string literal)
{
	const std::string error = "impossible";
	int num;

	num = atoi(literal.c_str());
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

void printNumber(std::string literal)
{
	const std::string error = "impossible";
	int numInt;
	double numDouble;
	char *end;

	numInt = atoi(literal.c_str());
	numDouble = strtod(literal.c_str(), &end);
	if (numDouble - numInt == 0)
	{
		if (numInt <= UCHAR_MAX)
		{
			if (isprint(numInt))
				std::cout << "char: " << "'" << static_cast<char>(numInt) << "'" << std::endl;
			else
				std::cout << "char: " << "Non displayable" << std::endl;
		}
		else
			std::cout << "char: " << error << std::endl;
		std::cout << "int: " << static_cast<int>(numDouble) << std::endl;
		std::cout << std::showpoint << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(numDouble) << "f" << std::endl;
		std::cout << std::showpoint << std::fixed << std::setprecision(1) << "double: " << numDouble << std::endl;
	}
	else
	{
		std::cout << "char: " << error << std::endl;
		if (numDouble > INT_MAX || numDouble < INT_MIN)
			std::cout << "int: " << error << std::endl;
		else
			std::cout << "int: " << static_cast<int>(numDouble) << std::endl;
		if (numDouble > FLT_MAX || numDouble < FLT_MIN)
			std::cout << "float: " << error << std::endl;
		else
			std::cout << std::showpoint << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(numDouble) << "f" << std::endl;
		std::cout << std::showpoint << std::fixed << std::setprecision(1) << "double: " << numDouble << std::endl;		
	}
}

void printInfOrNan(std::string literal, int type)
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

void printError(void)
{
	const std::string error = "impossible";

	std::cout << "char: " << error << std::endl;
	std::cout << "int: " << error << std::endl;
	std::cout << "float: " << error << std::endl;
	std::cout << "double: " << error << std::endl;
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