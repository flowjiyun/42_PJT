/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:25:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/08/29 13:33:15 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: need input data file for first argument\n";
		return (1);
	}

	BitcoinExchange bitcoin("./data.csv");
	bitcoin.exchange(argv[1]);
	return (0);
}
