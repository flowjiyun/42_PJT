/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:51:24 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/21 15:31:24 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& rhs);
		virtual ~Cat();

		Brain* getBrain(void) const;
		virtual void makeSound(void) const;

	private:
		Brain *mBrain;	
};

#endif
