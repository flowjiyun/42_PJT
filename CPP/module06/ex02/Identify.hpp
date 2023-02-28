/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:59:44 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/28 17:24:41 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <exception>
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif