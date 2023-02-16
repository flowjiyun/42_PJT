/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:31:24 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/16 22:09:58 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::getRawBit(void) const
{
	std::cout << "getRawBits member fucntion called" <<std::endl;
	return (mFixedPointValue);
}

void Fixed::setRawBit(const int raw)
{
	mFixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)mFixedPointValue / (1 << mFractionalBit));
}

int Fixed::toInt(void) const
{
	return ((int)mFixedPointValue / (1 << mFractionalBit));
}

Fixed::Fixed()
	: mFixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
	: mFixedPointValue(value * (1 << mFractionalBit))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
	: mFixedPointValue(roundf(value * (1 << mFractionalBit)))
{
	std::cout << "Float constructor called" << std::endl;	
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
		mFixedPointValue = rhs.mFixedPointValue;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs)
{
	out << rhs.toFloat();
	return (out);
}