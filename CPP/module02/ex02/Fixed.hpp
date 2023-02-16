/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:31:32 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/16 21:53:21 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
class Fixed
{
	public:
		// orthodox canonical form
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& rhs);
		// operator overload(comparison)
		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;
		// operator overload(arithmetic)
		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;
		// operator overload(increment/decrement)
		Fixed&	operator++(void);
		Fixed	operator++(int dummy);
		Fixed&	operator--(void);
		Fixed	operator--(int dummy);

		int		getRawBit(void) const;
		void	setRawBit(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static			Fixed& min(Fixed& a, Fixed& b);
		static const	Fixed& min(const Fixed& a,  const Fixed& b);
		static			Fixed& max(Fixed& a, Fixed& b);
		static const	Fixed& max(const Fixed& a,  const Fixed& b);

	private:
		int					mFixedPointValue;
		static const int	mFractionalBit = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& rhs);

#endif