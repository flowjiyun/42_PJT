/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:29:31 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/21 15:21:22 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		mIdea[i] = "void";
}

Brain::Brain(const std::string type)
{
	std::cout << "Brain name constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		mIdea[i] = type;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		mIdea[i] = other.mIdea[i];	
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; ++i)
			mIdea[i] = rhs.mIdea[i];	
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
