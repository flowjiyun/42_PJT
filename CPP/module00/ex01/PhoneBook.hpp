/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:16:46 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/07 22:07:23y jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void	Add(const Contact& val);
		void	Search(void) const;
		void	PrintTable(void) const;
		int		GetNum(void) const;

	private:
		Contact	mBook[8];
		int		mIndex;
		int		mNum;
};

#endif