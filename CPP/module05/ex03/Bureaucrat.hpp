/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:14:03 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/23 15:05:18 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;
class Bureaucrat
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

		Bureaucrat();
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName(void) const;
		unsigned int	getGrade(void) const;
		void	increaseGrade(void);
		void	decreaseGrade(void);

		void	signForm(AForm& val) const;
		void	executeForm(const AForm& form) const;

	private:
		const std::string mName;
		unsigned int	mGrade;
		Bureaucrat& operator=(const Bureaucrat& rhs);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif