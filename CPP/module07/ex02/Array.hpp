/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:13:21 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/02 13:35:24 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>

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
		T& operator[](const unsigned int index);
		unsigned int size() const;

	private:
		unsigned int mSize;
		T* mArray;
};

template <typename T>
Array<T>::Array()
	: mSize(0)
{
	mArray = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
	: mSize(n)
{
	mArray = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	mSize = other.mSize;
	mArray = new T[mSize];
	for (unsigned int i = 0; i < mSize; ++i)
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
		mArray = new T[mSize];
		for (int i = 0; i < mSize; ++i)
		{
			mArray[i] = rhs.mArray[i];
		}
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](const unsigned int index)
{
		if (index < 0 || index >= mSize)
			throw OutOfBound();
		return (mArray[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (mSize);
}

#endif