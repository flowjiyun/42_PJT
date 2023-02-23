/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:05:44 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/23 15:14:36 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberryCreationForm", 145, 137, false)
	, mTarget(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getGradeSign(), other.getGradeExecute(), other.getIsSigned())
	, mTarget(other.mTarget)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::string fileName = mTarget + "_shrubbery";
	std::fstream file;
	file.open(fileName.c_str(), std::fstream::out);
	if (!file.is_open())
		throw FileNotOpenException();
	int height = 10;
	int space = height - 1;
    for (int i = 0; i < height; i++)
	{
        for (int j = 0; j < space; j++)
		{
            file << " ";
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            file << "*";
        }
        file << '\n';
        space--;
    }
    for (int i = 0; i < height - 1; i++) {
        file << " ";
    }
    file << "*" << '\n';
}