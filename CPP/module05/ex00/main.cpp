/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:13:39 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/20 17:18:46 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "=============test1================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 1);
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "=============test2================" << std::endl;
	try
	{
		Bureaucrat b("jiyun", 150);
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "=============test3================" << std::endl;
	try
	{
		Bureaucrat c("jiyun", 189);
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// std::cout << "=============test4================" << std::endl;
	// try
	// {
	// 	b.d
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << "OK" << std::endl;
	return (0);
}