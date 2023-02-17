/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:10:05 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/17 16:44:46 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	a("a");
	ClapTrap	b(a);
	ClapTrap	c("c");
	ClapTrap	d ("d");

	d = c;

	a.attack("1");
	a.takeDamage(5);
	a.beRepaired(5);
	for (int i = 0; i < 8; ++i)
		a.attack("2");
	a.beRepaired(5);
	return(0);
}