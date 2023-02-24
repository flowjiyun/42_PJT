/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:09:30 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/24 18:17:19 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

int checkType(const std::string literal)
{
	if (isFloatInfOrNan(literal))
		return (FLOATINF);
	if (isDoubleInfOrNan(literal))
		return (DOUBLEINF);	
	if (literal.length() == 1)
		return (CHAR);
	return (NUMBER);
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
			std::cout << "char: " << *literal.c_str() << std::endl;
	}
	if (isdigit(static_cast<int>(*literal.c_str())))
	{
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << "float: " << static_cast<float>(num) << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	else
	{
		std::cout << "int: " << error << std::endl;
		std::cout << "float: " << error << std::endl;
		std::cout << "double: " << error << std::endl;
	}
}

// void printNumber(double val)
// {

// }

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

void printNum(std::string literal)
{

}
void ScarlarConverter::convert(std::string literal)
{
	int type;

	type = checkType(literal);
	if (type == FLOATINF || type == DOUBLEINF)
		printInfOrNan(literal, type);
	else if (type == CHAR)
		printChar(literal);
	else
		printNum(literal);
}