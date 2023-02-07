/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:16:56 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/07 22:52:49by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	std::string cmd;
	Contact val;
	PhoneBook myPhoneBook;
	std::cout << "PLEASE USE CMD : ADD, SEARCH, EXIT" << '\n'; 
	while (true)
	{
		getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			val.SetData();
			myPhoneBook.Add(val);
		}
		else if (cmd == "SEARCH")
		{	
			myPhoneBook.PrintTable();
			if (myPhoneBook.GetNum() != 0)
				myPhoneBook.Search();
			else
				std::cout << "ADD Contact First" << "\n";
		}
		else if (cmd == "EXIT")
		{
			exit(0);
		}
		else
		{
			std::cout << "VALID CMD : ADD, SEARCH, EXIT" << '\n';
			std::cout << "Enter Valid CMD" << '\n';
		}
	}
	return (0);
}