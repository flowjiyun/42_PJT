/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:51:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/21 15:19:29 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const std::string type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& rhs);
		virtual ~AAnimal();

		std::string getType(void) const;
		virtual void makeSound(void) const = 0;

	protected:
		std::string mType;
};

#endif