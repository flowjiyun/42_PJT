/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:10:05 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/16 17:10:03 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap	a("a");
	FragTrap	b(a);
	FragTrap	c("c");
	FragTrap	d ("d");

	d = c;

	a.attack("1");
	a.takeDamage(5);
	a.beRepaired(5);
	for (int i = 0; i < 98; ++i)
		a.attack("2");
	a.beRepaired(5);
	a.highFivesGuys();
	return(0);
}