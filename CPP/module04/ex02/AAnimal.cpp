/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:50:22 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/19 17:59:30 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
	: mType("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string type)
	: mType(type)
{
	std::cout << "AAnimal name constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
	: mType(other.mType)
{	
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &rhs)
		mType = rhs.mType;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (mType);
}
