/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:10:16 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/07 21:30:03 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::SetFirstName(void)
{
	std::string val;
	std::cout << "Enter First Name :";
	getline(std::cin, val);
	mFirstName = val;
}

void	Contact::SetLastName(void)
{
	std::string val;
	std::cout << "Enter Last Name : ";
	getline(std::cin, val);
	mLastname = val;
}

void	Contact::SetNickname(void)
{
	std::string val;
	std::cout << "Enter Nickname : ";
	getline(std::cin, val);
	mNickname = val;
}

void	Contact::SetPhoneNumber(void)
{
	std::string val;
	std::cout << "Enter Phone Number : ";
	getline(std::cin, val);
	mPhoneNumber = val;
}

void	Contact::SetDarkestSecret(void)
{
	std::string val;
	std::cout << "Enter Darkest Secret : ";
	getline(std::cin, val);
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