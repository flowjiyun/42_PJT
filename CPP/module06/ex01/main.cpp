/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:33:23 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/06 17:07:37 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data data(10, 10.1f, 10.1);
	uintptr_t ptr;
	Data* dataDeserialized;
	
	ptr = Serializer::serialize(&data);
	dataDeserialized = Serializer::deserialize(ptr);

	std::cout << "Before serialized : " <<  &data << std::endl;
	std::cout << "After serialized: " << ptr << std::endl;
	std::cout << "After deserialized: " << dataDeserialized << std::endl;

	return (0);
}