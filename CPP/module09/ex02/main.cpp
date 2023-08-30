/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:06:27 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/08/30 09:54:10 by jiyunpar         ###   ########.fr       */
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
		PmergeMe<std::vector<int> > beforeSortVector(argv);
		PmergeMe<std::deque<int> > beforeSortDeque(argv);

		PmergeMe<std::vector<int> > inputInVector(beforeSortVector);
		PmergeMe<std::deque<int> > inputInDeque(beforeSortDeque);

		PmergeMe<std::vector<int> > testVector(inputInVector);
		PmergeMe<std::vector<int> > testVectorStl(inputInVector);

		PmergeMe<std::deque<int> > testDeque(inputInDeque);
		PmergeMe<std::deque<int> > testDequeStl(inputInDeque);

		// first line
		std::cout << "Before: ";
		beforeSortVector.printSequence();
		std::cout << '\n';
		//second line
		std::cout << "After: ";
		std::vector<int> dataInVector = inputInVector.getSequence();
		std::deque<int> dataInDeque = inputInDeque.getSequence();
		std::vector<int> validationVector = inputInVector.getSequence();
		std::deque<int> validationDeque = inputInDeque.getSequence();
		std::vector<int> afterSortVector = mergeInsertionSortInVector(dataInVector);
		std::deque<int> afterSortDeque = mergeInsertionSortInDeque(dataInDeque);
		sort(validationVector.begin(), validationVector.end());
		sort(validationDeque.begin(), validationDeque.end());
		for (size_t i = 0; i < afterSortVector.size(); ++i)
			std::cout << afterSortVector[i] << ' ';
		std::cout << '\n';
		if (validationVector == afterSortVector) {
			std::cout << "sort vector validation OK!!" << '\n';
		}
		if (validationDeque == afterSortDeque) {
			std::cout << "sort Deque validation OK!!" << '\n';
		}

    // vector result
    std::cout << "Vector container" << '\n';
		std::vector<int> testTimeVector = testVector.getSequence();
		gettimeofday(&startTime, NULL);
		std::cout << "time to process rangeof " << testTimeVector.size() << " element with ford-johnson : ";
		mergeInsertionSortInVector(testTimeVector);
		std::cout << get_time_from_base(startTime) << " usec\n";
		
		std::vector<int> testTimeVectorStl = testVectorStl.getSequence();
		gettimeofday(&startTime, NULL);
		std::cout << "time to process rangeof " << testTimeVectorStl.size() << " element with STL sort : ";
		sort(testTimeVectorStl.begin(), testTimeVectorStl.end());
		std::cout << get_time_from_base(startTime) << " usec\n";

    //deque result
    std::cout << "Deque container" << '\n';
		std::deque<int> testTimeDeque = testDeque.getSequence();
		gettimeofday(&startTime, NULL);
		std::cout << "time to process rangeof " << testTimeDeque.size() << " element with ford-johnson : ";
		mergeInsertionSortInDeque(testTimeDeque);
		std::cout << get_time_from_base(startTime) << " usec\n";
		
		std::deque<int> testTimeDequeStl = testDequeStl.getSequence();
		gettimeofday(&startTime, NULL);
		std::cout << "time to process rangeof " << testTimeDequeStl.size() << " element with STL sort : ";
		sort(testTimeDequeStl.begin(), testTimeDequeStl.end());
		std::cout << get_time_from_base(startTime) << " usec\n";
	}
	catch(int)
	{
		std::cout << "Error" << '\n';
	}
	

	return (0);
}