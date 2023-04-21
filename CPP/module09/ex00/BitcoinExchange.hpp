/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:48:27 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/21 17:41:11 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <exception>

class BitcoinExchange
{
	public:
		class FileOpenError : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		void exchange(std::string input) const;
		
	private:
		std::map<std::string, int> mDateWithPrice;	
};

#endif