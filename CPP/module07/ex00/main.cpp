/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:54:52 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/06 18:56:36 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Utils.hpp"

int main(void)
{
	// test
	int a = 1;
	int b = 2;

	std::cout << "------before swap------" << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	utils::swap(a , b);
	std::cout << "------after swap------" << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "min(a , b) : " << utils::min(a, b) << std::endl;
	std::cout << "max(a , b) : " << utils::max(a, b) << std::endl;
	

	std::string c = "chain1";
	std::string d = "chain2";

	std::cout << "------before swap------" << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "d : " << d << std::endl;
	utils::swap(c , d);
	std::cout << "------after swap------" << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "d : " << d << std::endl;
	std::cout << "min(c , d) : " << utils::min(c, d) << std::endl;
	std::cout << "max(c , d) : " << utils::max(c, d) << std::endl;

	return (0);
}