/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:58:58 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/21 18:08:24 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char* BitcoinExchange::FileOpenError::what(void) const throw()
{
	return ("Error : File open error\n");
}

std::string parseKey(std::string line)
{
	std::string key;
	size_t pos;

	pos = line.find(",");
	key = line.substr(0, pos);
	return (key);
}

double parseValue(std::string line)
{
	double value;
	size_t pos;
	
	pos = line.find(",");
	value = strtod((line.substr(pos + 1)).c_str(), NULL);
	return value;
}

std::map<std::string ,int> initPriceData(const std::string filepath)
{
	std::fstream file;
	std::map<std::string, double> ret;

	file.open(filepath.c_str(), std::ios::in);
	if (!file.is_open())
		throw BitcoinExchange::FileOpenError();
	//첫줄은 건너 뛰고 다음 줄 부터 읽기
	std::string first_line;
	std::getline(file, first_line);
	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		ret.insert({parseKey(line), parseValue(line)});	
	}
	
	
}

BitcoinExchange::BitcoinExchange()
{
	mDateWithPrice = initPriceData("./data.csv");
	
}