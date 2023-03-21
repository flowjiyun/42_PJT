/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:51:30 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/21 15:13:50 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	mBrain = new Brain("Cat");
}

Cat::Cat(const Cat& other)
	: Animal(other.mType)
{	
	std::cout << "Cat copy constructor called" << std::endl;
	mBrain = new Brain();
	*mBrain = *other.mBrain;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		mType = rhs.mType;
		delete mBrain;
		mBrain = new Brain();
		*mBrain = *rhs.mBrain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete mBrain;
}

Brain* Cat::getBrain(void) const
{
	return (mBrain);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!! Meow!!" << std::endl;
}

