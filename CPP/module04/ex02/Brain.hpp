/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:29:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/21 15:21:30 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain
{
	public:
		Brain();
		Brain(const std::string type);
		Brain(const Brain& other);
		Brain& operator=(const Brain& rhs);
		~Brain();

	private:
		std::string mIdea[100];
};
#endif