/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:13:39 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/21 18:13:36 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	// 제대로 생성이 되는지 확인
	std::cout << "=============test1================" << std::endl;
	try
	{
		Form	b("paper", 2, 2, false);
		std::cout << b << std::endl;
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// 올바르지 않은 grade로 Form 만들기
	std::cout << "=============test2================" << std::endl;
	try
	{
		Form	b("paper", 0, 2, false);
		std::cout << b << std::endl;
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// signForm & beSign 작동 확인 - 1
	// 정상 작동
	std::cout << "=============test3================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 1);
		Form	b("paper", 2, 2, false);
		std::cout << b << std::endl;
		a.signForm(b);
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// signForm & beSign 작동 확인 - 2
	// grade가 낮아서 서명 불가
	std::cout << "=============test4================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 3);
		Form	b("paper", 2, 2, false);
		std::cout << b << std::endl;
		a.signForm(b);
		std::cout << b << std::endl;
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// signForm & beSign 작동 확인 - 3
	// 이미 서명이된 문서이기 때문에 서명 불가
	std::cout << "=============test5================" << std::endl;
	try
	{
		Bureaucrat a("jiyun", 1);
		Form	b("paper", 2, 2, true);
		std::cout << b << std::endl;
		a.signForm(b);
		std::cout << b << std::endl;
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}