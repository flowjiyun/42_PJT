/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:38:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/07 12:59:18by jiyunpar         ###   ########.fr       */
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
    template<typename InputIterator>
		void addNumber(InputIterator begin, InputIterator end) {
      InputIterator begin_cp = begin, end_cp = end;
      size_t input_size = 0;
      while(begin_cp != end_cp) {
        ++begin_cp;
        ++input_size;
      }
      if (mCapacity - mSize < input_size) {
        throw MaxElement();
      }
      while (begin != end) {
        mVec.push_back(*begin);
        ++mSize;
        ++begin;
      }
    }
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

	private:
		std::vector<int> mVec;
		size_t mSize;
		size_t mCapacity;
		Span();
		
};

#endif