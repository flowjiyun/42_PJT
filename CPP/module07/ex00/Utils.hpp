/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:38:08 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/01 20:44:17 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace utils
{
	template <typename T>
	void swap(T& first, T& second)
	{
		T temp;
		
		temp = first;
		first = second;
		second = temp;
	}

	template <typename T>
	T min(T first, T second)
	{
		return (first < second ? first : second);
	}

	template <typename T>
	T max(T first, T second)
	{
		return (first > second ? first : second);
	}
}

#endif