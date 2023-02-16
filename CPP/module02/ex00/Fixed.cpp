/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:31:24 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/16 16:58:06 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::mFractionalBit = 8;

int	Fixed::getRawBit(void) const
{
	std::cout << "getRawBits member fucntion called" <<std::endl;
	return (mFixedPointValue);
}

void Fixed::setRawBit(const int raw)
{
	mFixedPointValue = raw * (1 << mFractionalBit);
}

Fixed::Fixed()
	: mFixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout <<"Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		mFixedPointValue = rhs.getRawBit();
	return (*this);
}
