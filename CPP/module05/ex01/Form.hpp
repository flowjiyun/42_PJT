/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:06:46 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/21 17:36:41 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
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

		Form();
		Form(const std::string& name, const unsigned int gradeSign, const unsigned int gradeExecute, bool isSigned);
		Form(const Form& other);
		~Form();

		const std::string& getName(void) const;
		unsigned int getGradeSign(void) const;
		unsigned int getGradeExecute(void) const;
		bool	getIsSigned(void) const;		

		void	beSigned(const Bureaucrat& val);
		
	private:
		const std::string mName;
		const unsigned int mGradeSign;
		const unsigned int mGradeExecute;
		bool	mIsSigned;
		Form& operator=(const Form& rhs);
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif