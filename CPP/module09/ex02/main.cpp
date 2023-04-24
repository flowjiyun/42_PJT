/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:06:27 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/24 18:50:38 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 1)	
	{
		std::cout << "Error" << '\n';
		return (1);
	}
	try
	{
		PmergeMe<std::vector<int> > inputTemp(argv);
		PmergeMe<std::vector<int> > inputInVector(inputTemp);
		PmergeMe<std::list<int> > inputInList(argv);

		// first line
		std::cout << "Before: ";
		inputTemp.printSequence();
		std::cout << '\n';
		inputTemp.sortWithAlgorithm();
		//second line
		std::cout << "After: ";
		inputTemp.printSequence();
		std::cout << '\n';

		std::vector<int> dataInVector = inputInVector.getSequence();
		std::list<int> dataInList = inputInList.getSequence();

		mergeInsertionSortInVector()

		
	}
	catch(int)
	{
		std::cout << "Error" << '\n';
	}
	

	return (0);
}