/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:26:36 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/28 16:37: by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base* generate(void)
{
	int num;

	srand(static_cast<unsigned int>(time(NULL)));
	num = rand();
	if (num % 3 == 0)
	{
		std::cout << "Class A Created!" << std::endl;
		return (new A());
	}
	else if (num % 3 == 1)
	{
		std::cout << "Class B Created!" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "Class C Created!" << std::endl;
		return (new C());
	}
}

void identify(Base* p)
{
	A* a;
	B* b;
	C* c;

	a = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << "The type of parameter is  A" << std::endl;
		return;
	}
	b = dynamic_cast<B*>(p);
	if (b != NULL)
	{
		std::cout << "The type of parameter is  B" << std::endl;
		return;
	}
	c = dynamic_cast<C*>(p);
	if (c != NULL)
	{
		std::cout << "The type of parameter is  C" << std::endl;
		return;
	}
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "The type of parameter is  A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "The type of parameter is  B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "The type of parameter is  C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}	
}
