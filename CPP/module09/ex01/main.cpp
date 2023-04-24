/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:03:57 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/24 15:23:44 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: not enough argument ex) ./RPN [operation in string]" << '\n';
		return (1);
	}
	std::string operation = argv[1];
	int ret;
	try
	{
		ret = doRpn(operation);
	}
	catch(int)
	{
		std::cout << "Error" << '\n';
	}
	
	return (0);
}
