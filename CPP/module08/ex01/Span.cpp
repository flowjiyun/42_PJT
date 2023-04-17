/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:38:26 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/17 16:30:13 by jiyunpar         ###   ########.fr       */
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
	mVec.reserve(mSize);
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

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	for (std::vector<int>::const_iterator it = begin; it != end; ++it)
	{
		if (mSize >= mCapacity)
			throw MaxElement();
		mVec.push_back(*it);
		++mSize;
	}
}

void Span::prinfNumber(void) const
{
	for (std::vector<int>::const_iterator it = mVec.begin(); it != mVec.end(); ++it)
		std::cout << *it << std::endl;
}

unsigned int Span::shortestSpan(void) const
{
	unsigned int min;
	std::vector<int> temp(mVec);

	min = UINT_MAX;
	sort(temp.begin(), temp.end());
	for (std::vector<int>::const_iterator it = temp.begin(); it != temp.end() - 1; ++it)
	{
		std::vector<int>::const_iterator itNext = it + 1;
		// exception check`
		if (*itNext - *it < min)
			min = *itNext - *it;
	}
	return (min);
}

unsigned int Span::longestSpan(void) const
{
	std::vector<int> temp(mVec);
	
	sort(temp.begin(), temp.end());
	return (temp.back() - temp.front());
}