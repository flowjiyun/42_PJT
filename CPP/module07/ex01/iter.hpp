/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:53:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/01 22:31:18 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void iter(T* array, int length, void (*func)(T&))
{
	if (array == NULL)
	{
		std::cout << "Error : array can't be null" << std::endl;
		return ;
	}
	for (int i = 0; i < length; ++i)
	{
		func(array[i]);
	}	
}

template <typename T>
void printVal(T& val)
{
	std::cout << "val is " << val << std::endl;
}

#endif