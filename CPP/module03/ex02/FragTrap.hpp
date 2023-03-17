/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:56:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/17 11:25:30 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string name);
		~FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& rhs);

		void	attack(const std::string& target);
		void	highFivesGuys(void) const;
};

#endif