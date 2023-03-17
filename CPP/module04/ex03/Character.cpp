/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:07:04 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/17 16:00:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name)
	: mName(name)
{
	mSlot = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		mSlot[i] = NULL;
}

Character::Character(const Character& other)
	: mName(other.mName)
{
	mSlot = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		mSlot[i] = other.mSlot[i];
}

Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		delete 
	}
}
