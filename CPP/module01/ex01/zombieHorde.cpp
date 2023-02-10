/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:18:28 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/10 13:38:15 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*ret;

	ret = new Zombie[n];
	for (int i = 0; i < n; ++i)
	{
		ret[i].setName(name);
	}
	return (ret);
}
