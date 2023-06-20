/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:13:21 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/06/20 16:40:25 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	public:
		class OutOfBound : public std::exception
		{
			public:
				virtual const char* what(void) const throw()
				{
					return ("Error : Out of Bound");
				}
		};
		Array();
		Array(unsigned int n);
		Array(const Array<T>& other);
		~Array();
		Array<T>& operator=(const Array<T>& rhs);
		T& operator[](const int index) const;
		size_t size(void) const;

	private:
		size_t mSize;
		T* mArray;
};

template <typename T>
Array<T>::Array()
	: mSize(0)
{
	mArray = new T[mSize];
}

template <typename T>
Array<T>::Array(unsigned int n)
	: mSize(n)
{
  // when add () after new, initiallize with default value
	mArray = new T[mSize]();
}

template <typename T>
Array<T>::Array(const Array<T>& other)
	:mSize(other.mSize)
{
	mArray = new T[mSize];
	for (size_t i = 0; i < mSize; ++i)
	{
		mArray[i] = other.mArray[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] mArray;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this != &rhs)
	{
		mSize = rhs.mSize;
		delete[] mArray;
		mArray = new T[mSize];
		for (size_t i = 0; i < mSize; ++i)
		{
			mArray[i] = rhs.mArray[i];
		}
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](const int index) const
{
		if (index < 0 || static_cast<size_t>(index) >= mSize)
			throw OutOfBound();
		return (mArray[index]);
}

template <typename T>
size_t Array<T>::size(void) const
{
	return (mSize);
}

#endif