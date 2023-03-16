/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:56:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/16 12:31:46 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string name);
		virtual ~ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& rhs);

		virtual void	attack(const std::string& target);
		void	guardGate(void) const;	

	private:
		ScavTrap();
};
#endif