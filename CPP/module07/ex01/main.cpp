/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:53:31 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/01 23:12:25 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	{
		std::cout << "int" << std::endl;
		int a[5] = {1, 2, 3, 4, 5};

		iter(a, 5, printVal);
	}

	{
		std::cout << "float" << std::endl;
		float a[5] = {0.1, 0.2, 0.3, 0.4, 0.5};

		iter(a, 5, printVal);
	}

	{
		std::cout << "string" << std::endl;

		std::string a[5] = {"a", "b", "c", "d", "e"};

		iter(a, 5, printVal);
	}
	return (0);
}