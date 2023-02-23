/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:13:39 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/23 16:06:14 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	// 제대로 생성되는지 확인
	std::cout << "=============test1================" << std::endl;
	try
	{
		ShrubberyCreationForm a("tree");
		Bureaucrat b("jiyun", 135);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		b.signForm(a);
		a.execute(b);
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	// 사인되지 않은 form을 집행하려고 할때 (오류1)
	std::cout << "=============test2================" << std::endl;
	try
	{
		ShrubberyCreationForm a("tree");
		Bureaucrat b("jiyun", 135);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		a.execute(b);
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	// 권한이 부족한 공무원이 form을 집행하려고 할때 (오류1)
	std::cout << "=============test3================" << std::endl;
	try
	{
		ShrubberyCreationForm a("tree");
		Bureaucrat b("jiyun", 140);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		b.signForm(a);
		a.execute(b);
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	// executeForm test
	std::cout << "=============test4================" << std::endl;
	try
	{
		ShrubberyCreationForm a("home");
		Bureaucrat b("jiyun1", 135);
		RobotomyRequestForm c("dog");
		Bureaucrat d("jiyun2", 40);
		PresidentialPardonForm e("prisoner");
		Bureaucrat f("jiyun3", 1);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << e << std::endl;
		std::cout << f << std::endl;
		// shruberry
		b.signForm(a);
		b.executeForm(a);
		//robot
		d.signForm(c);
		d.executeForm(c);
		//robot
		f.signForm(e);
		f.executeForm(e);
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return (0);
}