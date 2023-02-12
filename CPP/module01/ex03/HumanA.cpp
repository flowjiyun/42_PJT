/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:10:12 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/12 22:32:20 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon)
	: mWeapon(weapon)
	, mName(name)
{

}

void	HumanA::attack(void) const
{
	std::cout << mName << " attacks with their " << mWeapon.getType() << std::endl;
}
