/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:44:40 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/10 10:55:02 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
	: mName("void")
{	
	std::cout << "Zombie defalt constructor called" << std::endl;
}

Zombie::Zombie(std::string name)
	: mName(name)
{
	std::cout << "Zombie name constructor called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << mName << " died!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	mName = name;
}