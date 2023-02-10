/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:05:57 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/10 16:33:31 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string val = "HI THIS IS BRAIN";
	std::string	*stringPTR = &val;
	std::string	&stringREF = val;
	
	std::cout << "variable address : " << &val << std::endl;
	std::cout << "ptr held address : " << stringPTR << std::endl;
	std::cout << "ref held address : " << &stringREF << std::endl;

	std::cout << "variable value : " << val << std::endl;
	std::cout << "ptr pointed value : " << *stringPTR << std::endl;
	std::cout << "ref pointed value : " << stringREF << std::endl;

	return (0);
}