/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:24:10 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/17 16:33:20 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria* materia);
		virtual AMateria* createMateria(const std::string& type);
	private:
		AMateria **mBackup;
		int mCount;
};

#endif