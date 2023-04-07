/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:53:31 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/07 11:44:17 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	{
		std::cout << "--------int---------" << std::endl;
		int a[5] = {1, 2, 3, 4, 5};

		// void (*ptr)(int&) = 0;
		// iter(a, 5, ptr);
		iter(a, 5, printVal<int>);
	}

	{
		std::cout << "--------float---------" << std::endl;
		float a[5] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};

		iter(a, 5, printVal<float>);
	}

	{
		std::cout << "--------string---------" << std::endl;
		std::string a[5] = {"a", "b", "c", "d", "e"};

		iter(a, 5, printVal<std::string>);
	}
	return (0);
}