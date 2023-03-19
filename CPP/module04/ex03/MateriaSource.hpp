/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:24:10 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/19 16:06:20 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

# define MAXELEMENT 4

class AMateria;
class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& rhs);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria* materia);
		virtual AMateria* createMateria(const std::string& type);
	private:
		AMateria **mBackup;
};

#endif