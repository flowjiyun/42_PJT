/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:07:07 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/14 19:50:35 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(std::string name);
		Character(const Character& other); // Deep copy
		Character& operator=(const Character& rhs); // Deep copy
		virtual ~Character();

		virtual const std::string& getName(void) const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:
		Character();
		std::string mName;
		AMateria **mSlot;
};

#endif