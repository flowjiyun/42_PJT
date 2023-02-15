/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:31:32 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/15 22:47:19 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& rhs);
		int		getRawBit(void) const;
		void	setRawBit(const int raw);	

	private:
		int					mFixedPointValue;
		static const int	mFractionalBit;
};

const int Fixed::mFractionalBit = 8;

#endif