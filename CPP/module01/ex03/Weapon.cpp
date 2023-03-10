/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:10:15 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/10 15:03:54 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
	: mType("void")
{
	std::cout << "Weapon class default constructor called" << std::endl;
}

Weapon::Weapon(const std::string type)
	: mType(type)
{
	std::cout << "Weapon class name constructor called" << std::endl;
}

const std::string& Weapon::getType(void) const
{
	return (mType);
}

void	Weapon::setType(const std::string type)
{
	mType = type;
}
