/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:56:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/17 11:26:10 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& rhs);

		void	attack(const std::string& target);
		void	guardGate(void) const;	
};
#endif