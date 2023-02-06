#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	std::string cmd;
	Contact
	std::cout << "PLEASE USE CMD : ADD, SEARCH, EXIT" << '\n'; 
	while (true)
	{
		getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			//do
		}
		else if (cmd == "SEARCH")
		{
			//do
		}
		else if (cmd == "EXIT")
		{
			exit(0);
		}
		else
		{
			std::cout << "VALID CMD : ADD, SEARCH, EXIT" << '\n';
		}
	}
	return (0);
}