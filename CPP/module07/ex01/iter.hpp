/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:53:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/06/20 16:02:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T1, typename T2>
void iter(T1* array, size_t length, T2 func)
{
	if (array == NULL || func == NULL)
	{
		std::cout << "Error : array & funtion pointer can't be null" << std::endl;
		return ;
	}
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}	
}

template <typename T>
void printVal(const T& val)
{
	std::cout << "val is " << val << std::endl;
}

#endif