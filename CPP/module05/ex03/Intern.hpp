/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:12:05 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/28 21:45:53 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		class MakeFormFailException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& rhs);
		~Intern();

		AForm* makeForm(const std::string formName, const std::string target) const;

	private:
		AForm* makeShruberryCreationForm(const std::string target) const;
		AForm* makeRobotomyRequestForm(const std::string target) const;
		AForm* makePresidentialPardonForm(const std::string target) const;
		AForm* (Intern::*mFunPtr[3])(const std::string target) const;
};
#endif