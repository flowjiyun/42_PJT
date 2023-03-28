/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:23:04 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/28 15:45:54 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> a;

	a.push(5);
	a.push(10);

	MutantStack<int> b(a);
	std::cout << "a top is : " << a.top() << std::endl;
	std::cout << "b top is : " << b.top() << std::endl;

	a.pop();
	std::cout << "a size is " << a.size() << std::endl;

	for (int i = 0; i < 4; ++i)
	{
		a.push(15 + i * 5);
	}

	MutantStack<int>::iterator it = a.begin();
	MutantStack<int>::iterator ite = a.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(a);
	return(0);
}