/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:38:05 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/06 18:07:48 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	// test 1
	try
	{
		Span a(5);

		a.addNumber(6);
		a.addNumber(3);
		a.addNumber(17);
		a.addNumber(9);
		a.addNumber(11);	
		std::cout << "shortest span : " << a.shortestSpan() << std::endl;
		std::cout << "longest span : " << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	//test 2
	try
	{
		std::vector<unsigned int> a;
		
		for (int i = 0; i < 100; i+=2)
		{
			a.push_back(i);
		}
		
		Span b(5);
		b.addNumber(a.begin(), a.begin() + 4);
		std::cout << "shortest span : " << b.shortestSpan() << std::endl;
		std::cout << "longest span : " << b.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}