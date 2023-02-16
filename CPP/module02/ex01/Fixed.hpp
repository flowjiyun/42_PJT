/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:31:32 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/16 16:40:45 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
class Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& rhs);
		int		getRawBit(void) const;
		void	setRawBit(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					mFixedPointValue;
		static const int	mFractionalBit = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& rhs);

#endif