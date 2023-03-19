/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:47 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/19 15:23:42 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

class ICharacter;
class AMateria;
class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		virtual ~Cure();
		Cure& operator=(const Cure& rhs);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif
