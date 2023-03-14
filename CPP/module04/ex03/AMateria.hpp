/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:54:56 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/14 19:58:15 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	
	public:
		AMateria();
		AMateria(const std::string& type);
		virtual ~AMateria();

		const std::string& getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string mType;

	private:
		AMateria& operator=(const AMateria& rhs);
	
};

#endif