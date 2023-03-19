/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:49 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/19 15:44:52 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
	: AMateria("Cure")
{
}

Cure::Cure(const Cure& other)
	: AMateria(other.mType)
{
}

Cure::~Cure()
{
}

Cure& Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
		mType = rhs.mType;
	return (*this); 
}

AMateria* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}