/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:41:18 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/14 20:21:09 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	funPtr[0] = &Harl::debug;
	funPtr[1] = &Harl::info;
	funPtr[2] = &Harl::warning;
	funPtr[3] = &Harl::error;
}

void	Harl::debug(void)
{
	std::cout << "[debug]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[info]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[warning]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[error]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levelArray[4] = {"debug", "info", "warning", "error"};
	int		index = -1;
	for (int i = 0; i < 4; ++i)
	{
		if (levelArray[i] == level)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
		(this->*funPtr[index])();
	else
		std::cout << "bad level!" << std::endl;
}
