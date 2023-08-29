/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:48:27 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/08/29 11:51:24 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <exception>
#include <ctime>
#include <cstring>

class BitcoinExchange
{
	public:
		class Error : public std::exception
		{
			public:
				Error(const std::string message, const std::string value);
				Error(const Error& other);
				~Error() throw();
				Error& operator=(const Error& rhs);
				virtual const char* what(void) const throw();
				std::string getErrorValue() const;
			private:
				std::string mErrorMessage;
				std::string mValue;
				Error();
		};

		BitcoinExchange(const char* datapath);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void exchange(std::string input) const;
		
	private:
		std::map<time_t, double> mDateWithPrice;	
		BitcoinExchange();
};

#endif
