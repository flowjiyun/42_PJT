/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:33:23 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/27 16:29:12 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	uintptr_t ptr;
	Data* dataDeserialized;
	
	data.a = 42;
	data.b = 42.42f;
	data.c = 42.42;
	ptr = Serializer::serialize(&data);
	dataDeserialized = Serializer::deserialize(ptr);

	std::cout << "Before serialized : " <<  &data << std::endl;
	std::cout << "After serialized: " << ptr << std::endl;
	std::cout << "After deserialized: " << dataDeserialized << std::endl;

	return (0);
}