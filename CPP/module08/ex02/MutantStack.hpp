/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:23:16 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/07 16:56:11 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::
		std::deque<T>
};
#endif