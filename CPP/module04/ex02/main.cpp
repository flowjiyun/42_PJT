/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:49:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/21 15:37:21 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	{
		std::cout << "===========Test1============" << std::endl;
		AAnimal *cage[4];

		// init AAnimal pointer array
		for (int i = 0; i < 4; ++i)
		{
			if (i < 2)
				cage[i] = new Cat();
			else
				cage[i] = new Dog();
		}

		// make sound
		for (int i = 0; i < 4; ++i)
			cage[i]->makeSound();

		// delete AAnimal	
		for (int i = 0; i < 4; ++i)
			delete cage[i];
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

	// std::cout << "===========Test4============" << std::endl;
	// {
	// 	AAnimal animal;
	// }
	// system("leaks ex01");
	return (0);
}