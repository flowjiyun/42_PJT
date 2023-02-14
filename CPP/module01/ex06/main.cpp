/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:41:02 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/14 20:20:23 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	getIndex(std::string &level)
{
	const std::string	levelArray[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; ++i)
	{
		if (levelArray[i] == level)
			return (i);
	}
	return (-1);
}
int main(int argc, char **argv)
{
	std::string level;
	Harl	a;
	int		index;
	if (argc != 2)
	{
		std::cout << "Input Error! : only debug, info, warning, error" << std::endl;
	}
	level = argv[1];
	index = getIndex(level);
	switch(index)
	{
		default:
			a.complain("badlevel");
			break;
		case 0:
			a.complain("debug");
			std::cout << "\n";
		case 1:
			a.complain("info");
			std::cout << "\n";
		case 2:
			a.complain("warning");
			std::cout << "\n";
		case 4:
			a.complain("error");
	}
	return (0);
}