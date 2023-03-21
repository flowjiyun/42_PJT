/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:07:04 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/21 16:20:07 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
	: mName("")
{
	mSlot = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		mSlot[i] = NULL;
}

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
	{
		if (other.mSlot[i] == NULL)
		{
			mSlot[i] = NULL;
			continue;
		}
		mSlot[i] = other.mSlot[i]->clone();
	}
}

Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		mName = rhs.mName;
		for (int i = 0; i < 4; ++i)
		{
			delete mSlot[i];
			if (rhs.mSlot[i] == NULL)
			{
				mSlot[i] = NULL;
				continue;
			}
			mSlot[i] = rhs.mSlot[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		delete mSlot[i];
	delete[] mSlot;
}

const std::string& Character::getName(void) const
{
	return (mName);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (mSlot[i] == NULL)
		{
			mSlot[i] = m;
			break;
		}
		else
			continue;
	}	
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		mSlot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (mSlot[idx] != NULL)
		mSlot[idx]->AMateria::use(target);
}

AMateria* Character::backUp(int idx) const
{
	return (mSlot[idx]);
}