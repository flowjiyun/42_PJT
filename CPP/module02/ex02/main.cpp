/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:31:18 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/16 14: by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	{
		std::cout << "========== subject test =============" << std::endl;
		Fixed a;
		Fixed const b(10.10f);
		Fixed c(5.05f);
		Fixed d(2);

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	{
		std::cout << "========== test comparision =============" << std::endl;
		const Fixed a(3);
		const Fixed b(3);
		const Fixed c(2.9f);
		const Fixed d(3.1f);

		std::cout << "Q : " << a << " == " << b << std::endl;
		std::cout << "A : " << (a == b) << std::endl;

		std::cout << "Q : " << a << " != " << b << std::endl;
		std::cout << "A : " << (a != b) << std::endl;

		std::cout << "Q : " << a << " < " << d << std::endl;
		std::cout << "A : " << (a < d) << std::endl;

		std::cout << "Q : " << a << " > " << d << std::endl;
		std::cout << "A : " << (a > d) << std::endl;

		std::cout << "Q : " << a << " >= " << c << std::endl;
		std::cout << "A : " << (a >= c) << std::endl;

		std::cout << "Q : " << a << " <= " << c << std::endl;
		std::cout << "A : " << (a <= c) << std::endl;

		std::cout << "Q : " << a << " <= " << b << std::endl;
		std::cout << "A : " << (a <= b) << std::endl;
	}

	{
		std::cout << "========== test arithmetic =============" << std::endl;
		const Fixed a(10.0f);
		const Fixed b(2.5f);

		std::cout << "Q : " << a << " + " << b << std::endl;
		std::cout << "A : " << (a + b) << std::endl;

		std::cout << "Q : " << a << " - " << b << std::endl;
		std::cout << "A : " << (a - b) << std::endl;

		std::cout << "Q : " << a << " * " << b << std::endl;
		std::cout << "A : " << (a * b) << std::endl;

		std::cout << "Q : " << a << " / " << b << std::endl;
		std::cout << "A : " << (a / b) << std::endl;
	}

	{
		std::cout << "========== test min, max =============" << std::endl;
		const Fixed a(10.0f);
		const Fixed b(2.5f);

		std::cout << "Q : " << "min : " <<  a << " , " << b << std::endl;
		std::cout << "A : " << Fixed::min(a, b) << std::endl;

		std::cout << "Q : " << "min : " <<  a << " , " << b << std::endl;
		std::cout << "A : " << Fixed::min(10.0f, 2.5f) << std::endl;

		std::cout << "Q : " << "max : " <<  a << " , " << b << std::endl;
		std::cout << "A : " << Fixed::max(a, b) << std::endl;

		std::cout << "Q : " << "max : " <<  a << " , " << b << std::endl;
		std::cout << "A : " << Fixed::max(10.0f, 2.5f) << std::endl;
	}
	return (0);
}