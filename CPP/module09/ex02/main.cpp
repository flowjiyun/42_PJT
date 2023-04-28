/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:06:27 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/28 19:20:43 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

long	get_time_from_base(struct timeval base_timeval)
{
	struct timeval	cur_timeval;
	long			cur_time;
	long			base_time;

	if (gettimeofday(&cur_timeval, NULL) != 0)
		return (-1);
	cur_time = cur_timeval.tv_sec * 1000000L + cur_timeval.tv_usec;
	base_time = base_timeval.tv_sec * 1000000L + base_timeval.tv_usec;
	return (cur_time - base_time);
}

int main(int argc, char** argv)
{
	if (argc == 1)	
	{
		std::cout << "Error" << '\n';
		return (1);
	}
	try
	{
		struct timeval startTime;
		PmergeMe<std::vector<int> > beforeSort(argv);
		PmergeMe<std::vector<int> > inputInVector(beforeSort);
		PmergeMe<std::vector<int> > testVector(inputInVector);
		PmergeMe<std::vector<int> > testVector1(inputInVector);

		// first line
		std::cout << "Before: ";
		beforeSort.printSequence();
		std::cout << '\n';
		//second line
		std::cout << "After: ";
		std::vector<int> dataInVector = inputInVector.getSequence();
		std::vector<int> afterSort = mergeInsertionSortInVector(dataInVector);
		for (size_t i = 0; i < afterSort.size(); ++i)
			std::cout << afterSort[i] << ' ';
		std::cout << '\n';

		std::vector<int> testTimeVector = testVector.getSequence();
		gettimeofday(&startTime, NULL);
		std::cout << "time to process rangeof " << testTimeVector.size() << " element : ";
		mergeInsertionSortInVector(testTimeVector);
		std::cout << get_time_from_base(startTime) << " usec\n";
		
		std::vector<int> testTimeVector1 = testVector1.getSequence();
		gettimeofday(&startTime, NULL);
		std::cout << "time to process rangeof " << testTimeVector1.size() << " element : ";
		sort(testTimeVector1.begin(), testTimeVector1.end());
		std::cout << get_time_from_base(startTime) << " usec\n";
	}
	catch(int)
	{
		std::cout << "Error" << '\n';
	}
	

	return (0);
}