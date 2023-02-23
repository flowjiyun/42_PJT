/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:06:46 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/23 12:06:54 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		class FileNotOpenException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		AForm();
		AForm(const std::string& name, const unsigned int gradeSign, const unsigned int gradeExecute, bool isSigned);
		AForm(const AForm& other);
		virtual ~AForm();

		const std::string& getName(void) const;
		unsigned int getGradeSign(void) const;
		unsigned int getGradeExecute(void) const;
		bool	getIsSigned(void) const;		

		void	beSigned(const Bureaucrat& val);

		virtual void execute(const Bureaucrat& executor) const = 0;
		
	private:
		const std::string mName;
		const unsigned int mGradeSign;
		const unsigned int mGradeExecute;
		bool	mIsSigned;
		AForm& operator=(const AForm& rhs);
};

std::ostream& operator<<(std::ostream& out, const AForm& rhs);

#endif