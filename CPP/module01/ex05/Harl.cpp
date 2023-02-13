/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:41:18 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/13 19:35:19 by jiyunpar         ###   ########.fr       */
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
	std::cout << "debug" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "info" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "warning" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "error" << std::endl;
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
