/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:49:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/21 11:30:37 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* k = new WrongCat();

	std::cout << "---------type test---------" << std::endl;
	std::cout << "good case for dog : " <<  j->getType() << std::endl;
	std::cout << "good case for cat : " << i->getType() << std::endl;
	std::cout << "bad case for WrongCat : " << k->getType() << std::endl;
	std::cout << "---------------------------" << std::endl;

	std::cout << "---------sound test---------" << std::endl;
	std::cout << "good case for dog : ";
	j->makeSound();
	std::cout << "good case for cat : ";
	i->makeSound();
	std::cout << "bad case for WrongCat : ";
	k->makeSound();

	delete j;
	delete i;
	delete k;
	// system("leaks ex00");
	return (0);
}