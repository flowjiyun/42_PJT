/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:10:24 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/17 22:36:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& rhs);

		virtual void	attack(const std::string& target) = 0;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
	protected:
		std::string		mName;
		unsigned int	mHitPoint; // hp
		unsigned int	mEnergyPoint; // mp
		unsigned int	mAttackDamage;
};
#endif