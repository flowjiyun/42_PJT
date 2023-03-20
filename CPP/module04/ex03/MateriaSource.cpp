/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:24:05 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/20 15:57:55 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	mBackup = new AMateria*[4];
	for (int i = 0; i < MAXELEMENT; ++i)
		mBackup[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < MAXELEMENT; ++i)
	{
		delete mBackup[i];
		mBackup[i] = other.mBackup[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < MAXELEMENT; ++i)
		{
			delete mBackup[i];
			mBackup[i] = rhs.mBackup[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAXELEMENT; ++i)
		delete mBackup[i];
	delete[] mBackup;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < MAXELEMENT; ++i)
	{
		if (mBackup[i] == NULL)
		{
			mBackup[i] = materia->clone();
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	AMateria* tmp;

	tmp = NULL;
	if (type == "ice" || type == "cure")
	{
		for (int i = 0; i < MAXELEMENT; ++i)
		{
			if (mBackup[i] != NULL)
			{
				if (type == "ice" && typeid(*mBackup[i]) == typeid(Ice))
					tmp = mBackup[i]->clone();
				else if (type == "cure" && typeid(*mBackup[i]) == typeid(Cure))
					tmp = mBackup[i]->clone();
			}
			else
				break;
		}
	}
	return (tmp);
}