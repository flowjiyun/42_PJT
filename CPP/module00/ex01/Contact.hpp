/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:10:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/09 11:16:22 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H
# include <iostream>
# include <string>
# include <iomanip>
# include "Ft.hpp"

class Contact
{	
	public:
		void	SetData(void);

		void	SetFirstName(void);
		void	SetLastName(void);
		void	SetNickname(void);
		void	SetPhoneNumber(void);
		void	SetDarkestSecret(void);

		std::string	GetFirstName(void) const;
		std::string	GetLastName(void) const;
		std::string	GetNickname(void) const;
		std::string	GetPhoneNumber(void) const;
		std::string	GetDarkestSecret(void) const;

	private:
		std::string mFirstName;
		std::string mLastname;
		std::string mNickname;
		std::string mPhoneNumber;
		std::string mDarkestSecret;
};

#endif