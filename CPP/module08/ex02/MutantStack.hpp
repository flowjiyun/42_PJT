/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:23:16 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/28 15:45:41 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack();
		MutantStack(const MutantStack<T>& other);
		~MutantStack();
		MutantStack<T>& operator=(const MutantStack<T>& rhs);

		const_iterator begin(void) const;
		iterator begin(void);
		const_iterator end(void) const;		
		iterator end(void);		
};

template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other)
	: std::stack<T>(other.c)
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& rhs)
{
	if (this != &rhs)
		this->c = rhs.c;
	return (*this);
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}
#endif