/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:55:04 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/19 15:48:53 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

AMateria::AMateria()
	: mType("")
{
}

AMateria::AMateria(const std::string& type)
	: mType(type)
{
}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	if (this != &rhs)
		mType = rhs.mType;
	return (*this);
}

const std::string& AMateria::getType(void) const
{
	return (mType);
}

void AMateria::use(ICharacter& target)
{
	Ice tmpIce = Ice();
	Cure tmpCure = Cure();

	if (typeid(*this) == typeid(Ice))
		tmpIce.use(target);
	else
		tmpCure.use(target);
}
