/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:53:48 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/28 20:50:48 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!\nrange : 1 <= grade <= 150");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!\nrange : 1 <= grade <= 150");
}

Bureaucrat::Bureaucrat()
	: mName("void")
	, mGrade(0)
{
	std::cout << "Constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
	: mName(name)
	, mGrade(grade)
{
	if (mGrade < 1)
		throw GradeTooHighException();
	else if (mGrade > 150)
		throw GradeTooLowException();
	std::cout << "Constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: mName(other.mName)
	, mGrade(other.mGrade)
{
	std::cout << "copied" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructed" << std::endl;
}

const std::string& Bureaucrat::getName(void) const
{
	return (mName);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (mGrade);
}

void Bureaucrat::increaseGrade(void)
{
	std::cout << "IncreaseGrade called"  << std::endl;
	--mGrade;
	if (mGrade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade(void)
{
	std::cout << "decreaseGrade called"  << std::endl;
	++mGrade;
	if (mGrade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (out);
}
