/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:06:52 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/21 18:01:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

const char* AForm::NotSignedException::what(void) const throw()
{
	return ("Form is not signed!");
}

const char* AForm::FileNotOpenException::what(void) const throw()
{
	return ("File not oppend!");
}

AForm::AForm()
	: mName("void")
	, mGradeSign(1)
	, mGradeExecute(1)
	, mIsSigned(false)
{
}

AForm::AForm(const std::string& name, const unsigned int gradeSign, const unsigned int gradeExecute, bool isSigned)
	: mName(name)
	, mGradeSign(gradeSign)
	, mGradeExecute(gradeExecute)
	, mIsSigned(isSigned)
{
	if (mGradeSign < 1 || mGradeExecute < 1)
		throw GradeTooHighException();
	if (mGradeSign > 150 || mGradeExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: mName(other.mName)
	, mGradeSign(other.mGradeSign)
	, mGradeExecute(other.mGradeExecute)
	, mIsSigned(other.mIsSigned)
{
}

AForm::~AForm()
{
}

const std::string& AForm::getName(void) const
{
	return (mName);
}

unsigned int AForm::getGradeSign(void) const
{
	return (mGradeSign);
}

unsigned int AForm::getGradeExecute(void) const
{
	return (mGradeExecute);
}

bool AForm::getIsSigned(void) const
{
	return (mIsSigned);
}

void AForm::beSigned(const Bureaucrat& val)
{
	if(val.getGrade() > mGradeSign)
		throw GradeTooLowException();
	mIsSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& rhs)
{
	out << "AForm name : " << rhs.getName() << std::endl;
	out << "AForm grade sign : " << rhs.getGradeSign() << std::endl;
	out << "AForm grade execute : " << rhs.getGradeExecute() << std::endl;
	out << "AForm is signed : " << rhs.getIsSigned();
	return (out);
}
