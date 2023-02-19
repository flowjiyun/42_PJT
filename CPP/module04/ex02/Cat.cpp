/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:51:30 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/19 16:36:39 by jiyunpar         ###   ########.fr       */
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
	: Animal(other.getType())
{	
	std::cout << "Cat copy constructor called" << std::endl;
	mBrain = new Brain();
	mBrain->setIdea(other.mBrain->getIdea());
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		mType = rhs.mType;
		mBrain = new Brain();
		mBrain->setIdea(rhs.mBrain->getIdea());
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete mBrain;
}

Brain& Cat::getBrain(void) const
{
	return (*mBrain);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!! Meow!!" << std::endl;
}

