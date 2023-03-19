/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:39:36 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/19 15:23:51 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "AMateria.hpp"

class ICharacter;
class AMateria;
class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		virtual ~Ice();
		Ice& operator=(const Ice& rhs);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif