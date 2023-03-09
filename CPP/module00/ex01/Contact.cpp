/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:10:16 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/09 11:51:29 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Ft.hpp"

void	Contact::SetFirstName(void)
{
	std::string val;
	std::cout << "Enter First Name : ";
	while (true)
	{
		Ft::getline(std::cin, val);
		if (val == "")
		{
			std::cout << "Enter First Name : ";
			continue;
		}
		else
			break;
	}
	mFirstName = val;
}

void	Contact::SetLastName(void)
{
	std::string val;
	std::cout << "Enter Last Name : ";
	while (true)
	{
		Ft::getline(std::cin, val);
		if (val == "")
		{
			std::cout << "Enter Last Name : ";
			continue;
		}
		else
			break;
	}
	mLastname = val;
}

void	Contact::SetNickname(void)
{
	std::string val;
	std::cout << "Enter Nickname : ";
	while (true)
	{
		Ft::getline(std::cin, val);
		if (val == "")
		{
			std::cout << "Enter Nickname : ";
			continue;
		}
		else
			break;
	}
	mNickname = val;
}

void	Contact::SetPhoneNumber(void)
{
	std::string val;
	std::cout << "Enter Phone Number : ";
	while (true)
	{
		Ft::getline(std::cin, val);
		if (val == "")
		{
			std::cout << "Enter Phone Number : ";
			continue;
		}
		else
			break;
	}
	mPhoneNumber = val;
}

void	Contact::SetDarkestSecret(void)
{
	std::string val;
	std::cout << "Enter Darkest Secret : ";
	while (true)
	{
		Ft::getline(std::cin, val);
		if (val == "")
		{
			std::cout << "Enter Darkest Secret : ";
			continue;
		}
		else
			break;
	}
	mDarkestSecret = val;
}

std::string	Contact::GetFirstName(void) const
{
	return (mFirstName);
}

std::string	Contact::GetLastName(void) const
{
	return (mLastname);
}

std::string	Contact::GetNickname(void) const
{
	return (mNickname);
}

std::string	Contact::GetPhoneNumber(void) const
{
	return (mPhoneNumber);
}

std::string	Contact::GetDarkestSecret(void) const
{
	return (mDarkestSecret);	
}

void	Contact::SetData(void)
{
	SetFirstName();
	SetLastName();
	SetNickname();
	SetPhoneNumber();
	SetDarkestSecret();
}