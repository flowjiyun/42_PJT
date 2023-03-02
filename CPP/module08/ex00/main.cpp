/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:16:08 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/02 18:11:18 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"


int main(void)
{
	std::vector<int> a;
	int n;
	int toFind;
	std::cout << "size of vector: ";
	std::cin >> n;
	std::cout << "enter number that you want to push back" << std::endl;
	for (int i = 0 ; i < n; ++i)
	{
		int val;
		std::cin >> val;
		a.push_back(val);
	}
	std::cout << "enter number that you want to find" << std::endl;
	std::cin >> toFind;
	std::vector<int>::iterator it = easyfind(a, toFind);
	if (it != a.end())
		std::cout << *it << std::endl;
	else
		std::cout << "Can not find number in container!" << std::endl;
	return(0);
}