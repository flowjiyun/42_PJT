/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:47 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/14 19:08:56 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

# include "AMateria.hpp"

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
