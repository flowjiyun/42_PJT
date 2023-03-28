/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:07:02 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/28 21:28:19 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5, false)
	, mTarget(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other.getName(), other.getGradeSign(), other.getGradeExecute(), other.getIsSigned())
	, mTarget(other.mTarget)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox." << std::endl;	
}