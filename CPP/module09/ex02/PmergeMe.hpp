/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:06:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/24 19:02:48 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <ctime>

template<typename T>
class PmergeMe
{
	public:
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe<T>& other);
		~PmergeMe();
		PmergeMe<T>& operator=(const PmergeMe<T>& rhs);

		T getSequence() const;
		void printSequence() const;
		void sortWithAlgorithm();
	private:
		T mSequence;
		PmergeMe();
};

template<typename T>
PmergeMe<T>::PmergeMe(char **argv)
{
	int i = 1;
	while (argv[i])
	{
		int val;
		val = atoi(argv[i]);
		if (val < 0)
			throw -1;
		mSequence.push_back(val);
		++i;
	}
}

template<typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T>& other)
	:mSequence(other.mSequence)
{
}

template<typename T>
PmergeMe<T>::~PmergeMe()
{
}

template<typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe<T>& rhs)
{
	if (this != & rhs)
		mSequence = rhs.mSequence;
	return (*this);
}

template<typename T>
void PmergeMe<T>::printSequence() const
{
	for (typename T::const_iterator it = mSequence.begin(); it != mSequence.end(); ++it)
		std::cout << *it << ' ';
}

template<typename T>
T PmergeMe<T>::getSequence() const
{
	return (mSequence);
}

template<typename T>
void PmergeMe<T>::sortWithAlgorithm()
{
	sort(mSequence.begin(), mSequence.end());
}


void	mergeInsertionSortInVector(std::vector<int>::iterator start, std::vector<int>::iterator end);
{
	std::distance(start, end);
	
}
#endif