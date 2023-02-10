/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:38:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/10 13:41:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*obj;
	const int	NUM = 3;

	obj = zombieHorde(NUM, "jiyun");
	for (int i = 0; i < NUM; ++i)
	{
		obj[i].announce();
	}
	delete[] obj;
	return (0);
}