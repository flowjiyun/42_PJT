/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:10:05 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/17 18:18:32 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	a("a");
	ScavTrap	b(a);
	ScavTrap	c("c");
	ScavTrap	d ("d");

	d = c;

	a.attack("1");
	a.takeDamage(5);
	a.beRepaired(5);
	for (int i = 0; i < 8; ++i)
		a.attack("2");
	a.beRepaired(5);
	a.guardGate();
	return(0);
}