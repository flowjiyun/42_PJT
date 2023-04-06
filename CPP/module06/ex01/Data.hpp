/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:09:23 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/06 16:18:45 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	public:
		Data();
		~Data();
		Data(const int mInt, const float mFloat, const double mDouble);
		Data(const Data& other);
		Data& operator=(const Data& rhs);

	private:
		int mInt;
		float mFloat;
		double mDouble;
};

#endif