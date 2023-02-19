/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:29:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/19 16:46:41 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>
# include <cstdlib>

class Brain
{
	public:
		Brain();
		Brain(const std::string type);
		Brain(const Brain& other);
		Brain& operator=(const Brain& rhs);
		~Brain();

		void setIdea(std::string (&val)[100]);
		std::string (&getIdea(void))[100];
		void printIdea(void) const;

	private:
		std::string mIdea[100];
};
#endif