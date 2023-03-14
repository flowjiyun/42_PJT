/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:55:04 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/14 19:58:23 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
	: mType("void")
{
}

AMateria::AMateria(const std::string& type)
	: mType(type)
{
}

AMateria::~AMateria()
{
}

// AMateria& AMateria::operator=(const AMateria& rhs)
// {
// 	if (this != &rhs)
// 		mType = rhs.mType;
// 	return (*this);
// }

const std::string& AMateria::getType(void) const
{
	return (mType);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Abstract class do nothing" << std::endl;
}
