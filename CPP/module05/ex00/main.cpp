/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:13:39 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/21 16:18:09 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "=============test1================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 1);
		std::cout << a << std::endl;
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "=============test2================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 150);
		std::cout << a << std::endl;
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "=============test3================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 189);
		std::cout << a << std::endl;
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "=============test4================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 150);
		std::cout << a << std::endl;
		a.decreaseGrade();
		std::cout << a << std::endl;
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "=============test5================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 1);
		std::cout << a << std::endl;
		a.increaseGrade();
		std::cout << a << std::endl;
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "=============test6================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 2);
		std::cout << a << std::endl;
		a.increaseGrade();
		std::cout << a << std::endl;

		Bureaucrat b("jiyun2", 1);
		std::cout << b << std::endl;
		b.decreaseGrade();
		std::cout << b << std::endl;
		std::cout << "OK" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	

	std::cout << "=============test7================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 1);
		std::cout << a << std::endl;
		std::cout << "OK" << std::endl;

		Bureaucrat b(a);
		std::cout << b << std::endl;
		std::cout << "OK" << std::endl;

		Bureaucrat c(Bureaucrat("hello", 189));
		std::cout << b << std::endl;
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}