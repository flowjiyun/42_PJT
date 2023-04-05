/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:13:39 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/05 09:47:20 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	//create form & executeForm test
	std::cout << "=============test1================" << std::endl;

		Intern intern;

		AForm *temp;
		Bureaucrat b("jiyun1", 45);

		temp = intern.makeForm("RobotomyrequestForm", "Bender");
		// shruberry
		b.signForm(*temp);
		b.executeForm(*temp);
		std::cout << "OK" << std::endl;

	return (0);
}