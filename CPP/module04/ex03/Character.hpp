/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:07:07 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/14 15:51:19 by jiyunpar         ###   ########.fr       */
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
		~Character();
	private:
		
	
};
#endif