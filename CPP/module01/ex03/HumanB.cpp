/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:10:08 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/12 22:34:21 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name)
	: mName(name)
{

}

void	HumanB::setWeapon(Weapon &weapon)
{
	mWeapon = &weapon;
}

void	HumanB::attack(void) const
{
	std::cout << mName << " attacks with their " << mWeapon->getType() << std::endl;
}
