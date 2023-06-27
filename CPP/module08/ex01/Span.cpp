/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:38:26 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/06/27 17:54:36 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char* Span::MaxElement::what(void) const throw()
{
	return ("Can't add Number : Max Element");
}

const char* Span::NotEnoughElement::what(void) const throw()
{
	return ("Not Enough Elemnet to get Span");
}

Span::Span(unsigned int max)
	: mSize(0)
	, mCapacity(max)
{
	mVec.reserve(mCapacity);
}

Span::Span(const Span& other)
{
	mSize = other.mSize;
	mCapacity = other.mCapacity;
	mVec = other.mVec;
}

Span::~Span()
{

}

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		mSize = rhs.mSize;
		mCapacity = rhs.mCapacity;
		mVec = rhs.mVec;
	}
	return (*this);
}

void Span::addNumber(int val)
{
	if (mSize >= mCapacity)
		throw MaxElement();
	else
	{
		mVec.push_back(val);
		++mSize;
	}
}

unsigned int Span::shortestSpan(void) const
{
  if (mSize <= 1) {
    throw NotEnoughElement();
  }
  unsigned int min;
	std::vector<int> temp(mVec);

	min = UINT_MAX;
	sort(temp.begin(), temp.end());
	for (std::vector<int>::const_iterator it = temp.begin(); it != temp.end() - 1; ++it)
	{
		std::vector<int>::const_iterator itNext = it + 1;
		if (static_cast<unsigned int>(*itNext - *it) < min)
			min = *itNext - *it;
	}
	return (min);
}

unsigned int Span::longestSpan(void) const
{
  if (mSize <= 1) {
    throw NotEnoughElement();
  }
	std::vector<int> temp(mVec);
	
	sort(temp.begin(), temp.end());
	return (temp.back() - temp.front());
}