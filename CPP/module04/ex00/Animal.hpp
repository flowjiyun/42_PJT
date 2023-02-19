/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:51:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/19 14:33:00 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal
{
	public:
		Animal();
		Animal(const std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal();

		std::string getType(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string mType;
};

#endif