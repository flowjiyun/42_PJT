/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:56:47 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/17 18:05:57by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	mHitPoint = 100;
	mEnergyPoint = 100;
	mAttackDamage = 30;
}

FragTrap::FragTrap(const std::string name)
	: ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	mHitPoint = 100;
	mEnergyPoint = 100;
	mAttackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap()
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	mName = other.mName;
	mHitPoint = other.mHitPoint;
	mEnergyPoint = other.mEnergyPoint;
	mAttackDamage = other.mAttackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		mName = rhs.mName;
		mHitPoint = rhs.mHitPoint;
		mEnergyPoint = rhs.mEnergyPoint;
		mAttackDamage = rhs.mAttackDamage;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "Let's high five!!" << std::endl;
}