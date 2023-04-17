/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:38:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/07 12:59:18 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>
# include <climits>

class Span
{
	public:
		class MaxElement : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		class NotEnoughElement : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		Span(unsigned int max);
		Span(const Span& other);
		~Span();
		Span& operator=(const Span& rhs);

		void addNumber(int val);
		void addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
		void prinfNumber(void) const;

	private:
		std::vector<int> mVec;
		unsigned int mSize;
		unsigned int mCapacity;
		Span();
		
};

#endif