/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:53:48 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/23 15:15:54 by jiyunpar         ###   ########.fr       */
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

const char* Bureaucrat::NotSignedException::what(void) const throw()
{
	return ("Form is not signed");
}

Bureaucrat::Bureaucrat()
	: mName("void")
	, mGrade(0)
{
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
	: mName(name)
	, mGrade(grade)
{
	if (mGrade < 1)
		throw GradeTooHighException();
	if (mGrade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: mName(other.mName)
	, mGrade(other.mGrade)
{
}

Bureaucrat::~Bureaucrat()
{
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
	--mGrade;
	if (mGrade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade(void)
{
	++mGrade;
	if (mGrade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& val) const
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

void	Bureaucrat::executeForm(const AForm& val) const
{
	try
	{
		if (val.getIsSigned() == false)
			throw NotSignedException();
		else
		{
			val.execute(*this);
			std::cout << mName << " executed " << val.getName() << std::endl;
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
