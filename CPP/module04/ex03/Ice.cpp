/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:45 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/19 15:44:19 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
}

Ice::Ice(const Ice& other)
	: AMateria(other.mType)
{
}

Ice::~Ice()
{
}

Ice& Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
		mType = rhs.mType;
	return (*this); 
}

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
