/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:50:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/21 15:31:55 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: AAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	mBrain = new Brain("Dog");
}

Dog::Dog(const Dog& other)
	: AAnimal(other.getType())
{	
	std::cout << "Dog copy constructor called" << std::endl;
	mBrain = new Brain();
	*mBrain = *other.mBrain;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		mType = rhs.mType;
		delete mBrain;
		mBrain = new Brain();
		*mBrain = *rhs.mBrain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete mBrain;
}

Brain* Dog::getBrain(void) const
{
	return (mBrain);
}

void Dog::makeSound(void) const
{
	std::cout << "Bark!! Bark!!" << std::endl;
}
