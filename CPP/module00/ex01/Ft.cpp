/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:13:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/09 11:22:54 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ft.hpp"

void Ft::getline(std::istream& in, std::string& val)
{
	in.clear();
	std::getline(in, val);
	if (in.eof())
		exit(0);
}