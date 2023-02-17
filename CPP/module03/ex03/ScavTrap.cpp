/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:56:47 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/17 18:05:57by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	std::cout << "Scavtrap default constructor called" << std::endl;
	mHitPoint = 100;
	mEnergyPoint = 50;
	mAttackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name)
	: ClapTrap(name)
{
	std::cout << "Scavtrap name constructor called" << std::endl;
	mHitPoint = 100;
	mEnergyPoint = 50;
	mAttackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap()
{
	std::cout << "Scavtrap copy constructor called" << std::endl;
	mName = other.mName;
	mHitPoint = other.mHitPoint;
	mEnergyPoint = other.mEnergyPoint;
	mAttackDamage = other.mAttackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "Scavtrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		mName = rhs.mName;
		mHitPoint = rhs.mHitPoint;
		mEnergyPoint = rhs.mEnergyPoint;
		mAttackDamage = rhs.mAttackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (mHitPoint != 0 && mEnergyPoint != 0)
	{
		--mEnergyPoint;
		std::cout << "================================================" << std::endl;
		std::cout << "ScavTrap " << mName << " attack "
			<< target << ", causing " << mAttackDamage << " points of damage!" << std::endl;
		std::cout << "Hit Point : " << mHitPoint << std::endl;
		std::cout << "Energy Point : " << mEnergyPoint << std::endl;
	}
	else
	{
		std::cout << "================================================" << std::endl;
		std::cout << "Can't do anything" << std::endl;
		std::cout << "Hit Point : " << mHitPoint << std::endl;
		std::cout << "Energy Point : " << mEnergyPoint << std::endl;
	}
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap is in Gate Keeper mode!" << std::endl;
}