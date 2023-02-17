/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:10:05 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/17 23:20:53 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamonTrap.hpp"

int main(void)
{
	DiamondTrap a("Diamond");

	a.attack("hello");
	a.whoAmI();	
	return (0);
}