/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:49:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/21 15:15:43 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	{
		std::cout << "===========Test1============" << std::endl;
		Animal* animal[4];

		// init animal pointer array
		for (int i = 0; i < 4; ++i)
		{
			if (i < 2)
				animal[i] = new Cat();
			else
				animal[i] = new Dog();
		}

		// make sound
		for (int i = 0; i < 4; ++i)
			animal[i]->makeSound();

		// delete animal	
		for (int i = 0; i < 4; ++i)
			delete animal[i];
	}
		
	std::cout << "===========Test2============" << std::endl;
	{
		Cat a = Cat();
		Cat b = Cat(a);


		std::cout << "a's brain address : " << a.getBrain() << std::endl;
		std::cout << "b's brain address : " << b.getBrain() << std::endl;
	}

	std::cout << "===========Test3============" << std::endl;
	{
		Cat a = Cat();
		Cat b = Cat();

		a = b;

		std::cout << "a's brain address : " << a.getBrain() << std::endl;
		std::cout << "b's brain address : " << b.getBrain() << std::endl;
	}
	// system("leaks ex01");

	return (0);
}