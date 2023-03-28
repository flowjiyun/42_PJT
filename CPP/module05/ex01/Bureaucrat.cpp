/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:53:48 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/28 20:57:41 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

Bureaucrat::Bureaucrat()
	: mName("void")
	, mGrade(0)
{
	std::cout << "Bureaucrat Constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
	: mName(name)
	, mGrade(grade)
{
	if (mGrade < 1)
		throw GradeTooHighException();
	else if (mGrade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat Constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: mName(other.mName)
	, mGrade(other.mGrade)
{
	std::cout << "Bureaucrat copied" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructed" << std::endl;
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
	std::cout << "Bureaucrat IncreaseGrade called"  << std::endl;
	--mGrade;
	if (mGrade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade(void)
{
	std::cout << "Bureaucrat decreaseGrade called"  << std::endl;
	++mGrade;
	if (mGrade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(Form& val) const
{
	try
	{
		if (val.getIsSigned() == true)
		{
			std::cout << mName << " couldn't sign " << val.getName() << " because already signed." << std::endl;
			return ;
		}
		else
		{
			val.beSigned(*this);
			std::cout << mName << " signed " << val.getName() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << mName << " couldn't sign " << val.getName() << " because ";
		std::cout << e.what() << '\n';
	}	
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (out);
}
