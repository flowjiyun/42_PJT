/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:09:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/24 14:26:11 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//1. main 매개 변수의 타입을 감지
//2. 적당한 타입으로 static cast
//3. 

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error : argument num error" << std::endl;
		return (1);
	}
	ScarlarConverter::convert(argv[1]);
	return (0);
}