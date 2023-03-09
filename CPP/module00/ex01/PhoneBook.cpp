/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:16:44 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/09 11:55:02 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Ft.hpp"

PhoneBook::PhoneBook()
	: mIndex(0)
	, mNum(0)
{
}

int PhoneBook::GetNum(void) const
{
	return (mNum);
}

void PhoneBook::Add(const Contact& val)
{
	if (mIndex < 8)
	{
		mBook[mIndex] = val;
		++mIndex;
		if (mNum < 8)
			++mNum;
	}
	else
	{
		mIndex = 0;
		mBook[mIndex] = val;
		++mIndex;
	}
}

static void PrintCategoty(void)
{
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "index";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "nick name";
	std::cout << "|" << "\n";
}

static void PrintRow(std::string val)
{
	if (strlen(val.c_str()) > 10)
	{
		std::cout << val.substr(0, 9);
		std::cout << ".";
	}
	else
	{
		std::cout << std::setw(10) << std::right << val;
	}
	std::cout << "|";
}

void PhoneBook::PrintTable(void) const
{
	PrintCategoty();
	if (mIndex != 0)
	{
		for (int i = 0; i < mNum; ++i)
		{
			std::cout << "|";
			std::cout << std::setw(10) << std::right << i + 1;
			std::cout << "|";
			PrintRow(mBook[i].GetFirstName());
			PrintRow(mBook[i].GetLastName());
			PrintRow(mBook[i].GetNickname());
			std::cout << "\n";
		}
	}
}

void PhoneBook::Search(void) const
{
	std::string index;
	std::cout << "Enter Index" << '\n';
	Ft::getline(std::cin, index);
	while (atoi(index.c_str()) < 1 || atoi(index.c_str()) > 8 || atoi(index.c_str()) > mNum)
	{
		std::cout << "Invalid Index : Enter Index in range" << "\n";
		Ft::getline(std::cin, index);
	}
	std::cout << "First Name : " << mBook[atoi(index.c_str()) - 1].GetFirstName() << '\n';
	std::cout << "Last Name : " << mBook[atoi(index.c_str()) - 1].GetLastName() << '\n';
	std::cout << "NickName : " << mBook[atoi(index.c_str()) - 1].GetNickname() << '\n';
	std::cout << "Phone Number : " << mBook[atoi(index.c_str()) - 1].GetPhoneNumber() << '\n';
	std::cout << "Darkest Secret : " << mBook[atoi(index.c_str()) - 1].GetDarkestSecret() << '\n';
}
