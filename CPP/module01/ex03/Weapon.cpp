/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:10:15 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/12 22:27:33 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(const std::string type)
	: mType(type)
{
	std::cout << "Weapon class constructed!" << std::endl;
}

const std::string& Weapon::getType(void) const
{
	return (mType);
}

void	Weapon::setType(const std::string type)
{
	mType = type;
}
