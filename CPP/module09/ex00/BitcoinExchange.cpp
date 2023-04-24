/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:58:58 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/24 13:00:35 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::Error::Error(const std::string message, const std::string value)
	:mErrorMessage(message)
	,mValue(value)
{
}

BitcoinExchange::Error::Error(const BitcoinExchange::Error& other)
	:mErrorMessage(other.mErrorMessage)
	,mValue(other.mValue)
{
}

BitcoinExchange::Error::~Error() throw()
{
}

BitcoinExchange::Error& BitcoinExchange::Error::operator=(const BitcoinExchange::Error& rhs)
{
	if (this != &rhs)
	{
		mErrorMessage = rhs.mErrorMessage;
		mValue = rhs.mValue;
	}
	return (*this);	
}

const char* BitcoinExchange::Error::what(void) const throw()
{
	return (mErrorMessage.c_str());
}

std::string BitcoinExchange::Error::getErrorValue() const
{
	return (mValue);
}

std::string parseKey(std::string line, std::string delimeter)
{
	std::string key;
	size_t pos;

	pos = line.find(delimeter);
	if (pos == std::string::npos)
		throw BitcoinExchange::Error("Error: Wrong date format", line);
	key = line.substr(0, pos);
	return (key);
}

double parseValue(std::string line, std::string delimeter, int flag = 0)
{
	double ret;
	std::string value;
	size_t pos;
	
	pos = line.find(delimeter);
	if (pos == std::string::npos)
		throw BitcoinExchange::Error("Error: Wrong date format", line);
	value = line.substr(pos + delimeter.length());
	ret = strtod(value.c_str(), NULL);
	if (flag != 0 && (ret < 0 || ret > 1000))
		throw BitcoinExchange::Error("Error: Date value out of range", value);
	return ret;
}

void checkLeapYear(int year, int month, int day, std::string key)
{
	if (month == 1)
	{
		// leap year
		if (year % 4 == 0)
		{
			if (year % 100 == 0)
			{
				if (year % 400 == 0)
				{
					if (day > 29)
						throw BitcoinExchange::Error("Error: Wrong date format", key);
				}
				else
				{
					if (day > 28)
						throw BitcoinExchange::Error("Error: Wrong date format", key);
				}

			}
			else
			{
				if (day > 29)
					throw BitcoinExchange::Error("Error: Wrong date format", key);
			}
		}
		else
		{
			if (day > 28)
				throw BitcoinExchange::Error("Error: Wrong date format", key);
		}

	}
	return;
}

void checkMaxDay(int month, int day, std::string key)
{
	if (month < 7)
	{
		if (month % 2 != 0)
		{
			if (day > 30)
				throw BitcoinExchange::Error("Error: Wrong date format", key);
		}
	}
	else
	{
		if (month % 2 == 0)
		{
			if (day > 30)
				throw BitcoinExchange::Error("Error: Wrong date format", key);
		}
	}
}

time_t dateToSecond(std::string key)
{
	struct tm	dateInfo;
	size_t pos;
	std::string year, month, day;

	memset(&dateInfo, 0, sizeof(dateInfo));
	// year
	pos = key.find("-");
	if (pos == std::string::npos)
		throw BitcoinExchange::Error("Error: Wrong date format", key);
	year = key.substr(0, pos);
	if (year.length() != 4)
		throw BitcoinExchange::Error("Error: Wrong date format", key);
	// month
	pos = key.find("-", pos + 1);
	if (pos == std::string::npos)
		throw BitcoinExchange::Error("Error: Wrong date format", key);
	month = key.substr(5, pos - 5);
	if (month.length() != 2)
		throw BitcoinExchange::Error("Error: Wrong date format", key);
	// day
	day = key.substr(pos + 1);
	if (day.length() != 2)
		throw BitcoinExchange::Error("Error: Wrong date format", key);

	dateInfo.tm_year = atoi(year.c_str()) - 1900;
	if (dateInfo.tm_year < 0)
		throw BitcoinExchange::Error("Error: Wrong date format", key);
	dateInfo.tm_mon = atoi(month.c_str()) - 1;
	if (dateInfo.tm_mon < 0 || dateInfo.tm_mon > 11)
		throw BitcoinExchange::Error("Error: Wrong date format", key);
	dateInfo.tm_mday = atoi(day.c_str());
	if (dateInfo.tm_mday < 1 || dateInfo.tm_mday > 31)
		throw BitcoinExchange::Error("Error: Wrong date format", key);
	checkLeapYear(dateInfo.tm_year, dateInfo.tm_mon, dateInfo.tm_mday, key);	
	checkMaxDay(dateInfo.tm_mon, dateInfo.tm_mday, key);
	return (mktime(&dateInfo));
}


std::map<time_t, double> initPriceData(const std::string filepath)
{
	std::fstream file;
	std::map<time_t, double> ret;

	file.open(filepath.c_str(), std::ios::in);
	if (!file.is_open())
		throw BitcoinExchange::Error("Error: File not open", "");
	//첫줄은 건너 뛰고 다음 줄 부터 읽기
	std::string first_line, line;
	std::getline(file, first_line);
	while (std::getline(file, line))
	{
		std::string key;
		double value;
		time_t timeInSec;
		try
		{
			key = parseKey(line, ",");
			value = parseValue(line, ",");
			timeInSec = dateToSecond(key);
			ret.insert(std::pair<time_t, double>(timeInSec, value));
		}
		catch(const BitcoinExchange::Error& e)
		{
			std::cout << e.what();
			std::cout << " => " << e.getErrorValue() << '\n';
		}	
	}
	return (ret);
}

BitcoinExchange::BitcoinExchange(const char* datapath)
{
	mDateWithPrice = initPriceData(datapath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	:mDateWithPrice(other.mDateWithPrice)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
		mDateWithPrice = rhs.mDateWithPrice;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

// void BitcoinExchange::exchange(void) const
// {
// 	std::map<time_t, double>::const_iterator it = mDateWithPrice.begin();
// 	int i = 0;
// 	while (i < 50)
// 	{
// 		std::cout << it->first << " : " << it->second << '\n';
// 		++i;
// 		++it;
// 	}
// }

void BitcoinExchange::exchange(void) const
{
	for (std::map<time_t, double>::const_iterator it = mDateWithPrice.begin(); it != mDateWithPrice.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << '\n';
	}
}

// void BitcoinExchange::exchange(std::string input) const
// {
// 	for (std::map<time_t, double>::const_iterator it = mDateWithPrice.begin(); it != mDateWithPrice.end(); ++it)
// 	{
// 		std::cout << it->first << " : " << it->second << '\n';
// 	}
// }
