/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:10:22 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/17 15:59:5 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
	: mName(name)
	, mHitPoint(10)
	, mEnergyPoint(10)
	, mAttackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: mName(other.mName)
	, mHitPoint(other.mHitPoint)
	, mEnergyPoint(other.mEnergyPoint)
	, mAttackDamage(other.mAttackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap copy assignmnet operator called" << std::endl;
	if (this != &rhs)
	{
		mName = rhs.mName;
		mHitPoint = rhs.mHitPoint;
		mEnergyPoint = rhs.mEnergyPoint;
		mAttackDamage = rhs.mAttackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (mHitPoint != 0 && mEnergyPoint != 0)
	{
		--mEnergyPoint;
		std::cout << "================================================" << std::endl;
		std::cout << "ClapTrap " << mName << " attack "
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (mHitPoint != 0 && mEnergyPoint != 0)
	{	
		mHitPoint -= amount;
		if (mHitPoint < 0)
			mHitPoint = 0;
		std::cout << "================================================" << std::endl;
		std::cout << "ClapTrap " << mName << " take damage " << amount << " Hit Point" << std::endl;
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

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (mHitPoint != 0 && mEnergyPoint != 0)
	{
		--mEnergyPoint;
		mHitPoint += amount;
		std::cout << "================================================" << std::endl;
		std::cout << "ClapTrap " << mName << " repaired " << amount << " Hit Point" << std::endl;
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
