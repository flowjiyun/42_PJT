/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:09:18 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/06 17:01:19 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCARLARCONVERTER_HPP
# define SCARLARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cctype>
# include <cfloat>
# include <iomanip>

enum
{
	FLOATINF,
	DOUBLEINF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
};

class ScarlarConverter
{
	public:
		static void	convert(std::string literal);
	private:
		ScarlarConverter();
		ScarlarConverter(const ScarlarConverter& other);
		~ScarlarConverter();
		ScarlarConverter& operator=(const ScarlarConverter& rhs);
};

#endif