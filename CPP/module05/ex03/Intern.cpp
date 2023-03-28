/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:12:00 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/28 21:46:30 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char* Intern::MakeFormFailException::what(void) const throw()
{
	return ("Make Form Fail");
}

Intern::Intern()
{
	mFunPtr[0] = &Intern::makeShruberryCreationForm;
	mFunPtr[1] = &Intern::makeRobotomyRequestForm;
	mFunPtr[2] = &Intern::makePresidentialPardonForm;
}

Intern::Intern(const Intern& other)
{
	mFunPtr[0] = other.mFunPtr[0];
	mFunPtr[1] = other.mFunPtr[1];
	mFunPtr[2] = other.mFunPtr[2];
}

Intern& Intern::operator=(const Intern& rhs)
{
	if (this != &rhs)
	{
		mFunPtr[0] = rhs.mFunPtr[0];
		mFunPtr[1] = rhs.mFunPtr[1];
		mFunPtr[2] = rhs.mFunPtr[2];
	}
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeShruberryCreationForm(const std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(const std::string target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(const std::string target) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string formName, const std::string target) const
{
	const std::string formArray[3] = {"ShrubberryCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int index = -1;
	AForm *ret;
	for (int i = 0; i < 3; ++i)
	{
		if (formArray[i] == formName)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		ret = (this->*mFunPtr[index])(target);
		return (ret);
	}
	else
	{
		throw(MakeFormFailException());
		return (NULL);
	}
}
