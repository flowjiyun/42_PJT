/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:06:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/25 16:35:03 by jiyunpar         ###   ########.fr       */
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

bool compare(int a, int b, const std::vector<int>& temp, const std::vector<int>& origin)
{
	return (origin[temp[a]] < origin[temp[b]]);
}

void sortVector(int size, std::vector<int>& origin, std::vector<int>& temp)
{
	if (size < 2)
	{	
		for (int i = 0; i < temp.size(); ++i)
			std::cout << temp[i] << ' ';
		return;
	}
	int remain = -1;
	std::vector<int> pairIndex;
	pairIndex.resize(origin.size(), -1);
	// 1. check pair & swap
	// 2. make pair index vector for radomaccess
	for (int i = 0; i < size / 2; ++i)
	{
		if (origin[temp[i]] < origin[temp[i + (size / 2)]])
		{
			std::swap(temp[i], temp[i + (size / 2)]);
			pairIndex[temp[i + (size / 2)]] = temp[i];
		}
		else
			pairIndex[temp[i]] = temp[i + (size / 2)];
	}
	if (size & 1)
		remain = temp[size - 1];
	std::cout << "size : " << size << '\n';
	std::cout << "temp before recursive : ";
	for (int i = 0; i < temp.size(); ++i)
		std::cout << temp[i] << ' ';
	std::cout << '\n';
	sortVector(size / 2, origin, temp);
	// 3. do binary search with saveed pair index by referencing real value of origin vector
	// 3-1 make vector for binary insert element (not sorted)
	std::vector<int> unsorted;
	unsorted.reserve(size / 2);
	for (int i = 0; i < size / 2; ++i)
		unsorted.push_back(pairIndex[temp[i]]);
	//3-2 get start index and binary search size with jacobsthal number
	int n = unsorted.size();
	int prevStart = -1;
	int i = 1;
	int curr = 2; // initial element of sequence
	while (prevStart < n - 1)
	{
		int j = std::min(prevStart + curr, n - 1);
		while (j > prevStart)
		{
				
			--j;
		}
		prevStart = std::min(prevStart + curr, n - 1);
		curr = ((1 << (i + 1)) - curr);
		++i;
	}	
}
void	mergeInsertionSortInVector(std::vector<int>& input)
{
	//make index vector
	std::vector<int> temp;
	for (int i = 0; i < input.size(); ++i)
		temp.push_back(i);
	//do merge insert sort
	sortVector(input.size(), input, temp);
}
#endif