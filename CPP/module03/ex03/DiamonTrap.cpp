/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:44:47 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/17 23:29:47 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamonTrap.hpp"

DiamondTrap::DiamondTrap()
	: ScavTrap()
	, FragTrap()
	, mName("void")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::mName = mName + "_clap_name";
	mHitPoint = 100;
	mEnergyPoint = 50;
	mAttackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string name)
	: ScavTrap()
	, FragTrap()
	, mName(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	ClapTrap::mName = mName + "_clap_name";
	mHitPoint = 100;
	mEnergyPoint = 50;
	mAttackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ScavTrap()
	, FragTrap()
	, mName(other.mName)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	ClapTrap::mName = mName + "_clap_name";
	mHitPoint = other.mHitPoint;
	mEnergyPoint = other.mEnergyPoint;
	mAttackDamage = other.mAttackDamage;	
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		mName = rhs.mName;
		ClapTrap::mName = mName + "_clap_name";
		mHitPoint = rhs.mHitPoint;
		mEnergyPoint = rhs.mEnergyPoint;
		mAttackDamage = rhs.mAttackDamage;	
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "ClapTrap name : " << ClapTrap::mName << std::endl;
	std::cout << "DiamondTrap name : " << mName << std::endl;
}
