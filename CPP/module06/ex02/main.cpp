/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:10:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/28 20:12:40 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main(void)
{
	Base* base;	

	base = generate();
	
	identify(base);
	Base& ref = *base;

	identify(ref);

	delete base;

	return (0);
}