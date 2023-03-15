/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:31:24 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/15 16:16:16 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::getRawBit(void) const
{
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
}

Fixed::Fixed(const int value)
	: mFixedPointValue(value * (1 << mFractionalBit))
{
}

Fixed::Fixed(const float value)
	: mFixedPointValue(roundf(value * (1 << mFractionalBit)))
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
		mFixedPointValue = rhs.mFixedPointValue;
	return (*this);
}

bool Fixed::operator>(const Fixed& rhs) const
{
	if (this->getRawBit() > rhs.getRawBit())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& rhs) const
{
	if (this->getRawBit() < rhs.getRawBit())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	if (this->getRawBit() >= rhs.getRawBit())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	if (this->getRawBit() <= rhs.getRawBit())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& rhs) const
{
	if (this->getRawBit() == rhs.getRawBit())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	if (this->getRawBit() != rhs.getRawBit())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed temp;

	temp.setRawBit(this->getRawBit() + rhs.getRawBit());
	return (temp);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed temp;

	temp.setRawBit(this->getRawBit() - rhs.getRawBit());
	return (temp);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed temp;

	temp.setRawBit((this->getRawBit() * rhs.getRawBit()) / (1 << mFractionalBit));
	return (temp);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed temp;

	temp.setRawBit((this->getRawBit() / rhs.getRawBit()) * (1 << mFractionalBit));
	return (temp);
}

Fixed& Fixed::operator++(void)
{
	this->mFixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int dummy)
{
	(void) dummy;
	Fixed temp(*this);
	this->mFixedPointValue++;	
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	this->mFixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int dummy)
{
	(void) dummy;
	Fixed temp(*this);
	this->mFixedPointValue--;	
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs)
{
	out << rhs.toFloat();
	return (out);
}
