/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:06:37 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/11 20:34:04 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750
int main(void)
{
    Array<int> numbers(MAX_VAL);
	Array<int> a;
	
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

	std::cout << "--------size() test------" << std::endl;
	std::cout << "MAX_VAL : " << MAX_VAL << std::endl;
	std::cout << "size of numbers : " << numbers.size() << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	std::cout << "--------check val------" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "numbers index " << i << ": " << numbers[i] << std::endl;
		std::cout << "mirror index " << i << ": " << mirror[i] << std::endl;
	}
	{
		std::cout << "----------check match---------" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		std::cout << "OK" << std::endl;
	}
    // copy & assignment test
    {
		std::cout << "------- copy & assignment test---------" << std::endl;
        Array<int> tmp = numbers;
        Array<int> test(tmp);

		for (int i = 0; i < 10; ++i)
		{
			std::cout << "numbers index " << i << ": " << numbers[i] << std::endl;
			std::cout << "tmp index " << i << ": " << tmp[i] << std::endl;
			std::cout << "test index " << i << ": " << test[i] << std::endl;
		}

    }
	std::cout << "---------out of bound test----------" <<std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror;
	// system("leaks ex02");
    return 0;
}