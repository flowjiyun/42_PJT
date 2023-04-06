/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:14:32 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/06 17:07:17 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
	: mInt(0)
	, mFloat(0.0f)
	, mDouble(0.0)
{
}

Data::~Data()
{
}

Data::Data(const Data& other)
	: mInt(other.mInt)
	, mFloat(other.mFloat)
	, mDouble(other.mDouble)
{
}

Data::Data(const int a, const float b, const double c)
{
	mInt = a;
	mFloat = b;
	mDouble = c;
}

Data& Data::operator=(const Data& rhs)
{
	if (this != &rhs)
	{
		mInt = rhs.mInt;
		mFloat = rhs.mFloat;
		mDouble = rhs.mDouble;
	}
	return (*this);
}
