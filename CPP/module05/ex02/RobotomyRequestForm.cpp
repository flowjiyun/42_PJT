/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:06:29 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/28 21:20:17 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45, false)
	, mTarget(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), other.getGradeSign(), other.getGradeExecute(), other.getIsSigned())
	, mTarget(other.mTarget)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	srand(time(NULL));
	int val = rand();
	if (val % 2 == 0)
		std::cout << mTarget << " robotomization success!!" << std::endl;
	else
		std::cout << mTarget << " robotomization fail!!" << std::endl;	
}