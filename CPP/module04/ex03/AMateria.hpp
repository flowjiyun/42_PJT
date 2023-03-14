/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:54:56 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/14 16:14:40 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string mType;
	
	public:
		AMateria(const std::string& type);
		const std::string& getType() const; //Returns the matera type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif