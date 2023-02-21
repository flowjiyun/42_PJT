/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:06:52 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/21 18:01:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

Form::Form()
	: mName("void")
	, mGradeSign(1)
	, mGradeExecute(1)
	, mIsSigned(false)
{
	std::cout << "Form Constructed" << std::endl;
}

Form::Form(const std::string& name, const unsigned int gradeSign, const unsigned int gradeExecute, bool isSigned)
	: mName(name)
	, mGradeSign(gradeSign)
	, mGradeExecute(gradeExecute)
	, mIsSigned(isSigned)
{
	if (mGradeSign < 1 || mGradeExecute < 1)
		throw GradeTooHighException();
	if (mGradeSign > 150 || mGradeExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form Constructed" << std::endl;
}

Form::Form(const Form& other)
	: mName(other.mName)
	, mGradeSign(other.mGradeSign)
	, mGradeExecute(other.mGradeExecute)
	, mIsSigned(other.mIsSigned)
{
	std::cout << "Form copied" << std::endl;
}

Form::~Form()
{
	std::cout << "destructed" << std::endl;
}

const std::string& Form::getName(void) const
{
	return (mName);
}

unsigned int Form::getGradeSign(void) const
{
	return (mGradeSign);
}

unsigned int Form::getGradeExecute(void) const
{
	return (mGradeExecute);
}

bool Form::getIsSigned(void) const
{
	return (mIsSigned);
}

void Form::beSigned(const Bureaucrat& val)
{
	if(val.getGrade() > mGradeSign)
		throw GradeTooLowException();
	mIsSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& rhs)
{
	out << "Form name : " << rhs.getName() << std::endl;
	out << "Form grade sign : " << rhs.getGradeSign() << std::endl;
	out << "Form grade execute : " << rhs.getGradeExecute() << std::endl;
	out << "Form is signed : " << rhs.getIsSigned();
	return (out);
}
