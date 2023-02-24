/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:09:18 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/24 17:43:16 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCARLARCONVERTER_HPP
# define SCARLARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cctype>

enum
{
	CHAR,
	NUMBER,
	FLOATINF,
	DOUBLEINF
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