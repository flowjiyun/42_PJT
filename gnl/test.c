/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:22:59 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/21 20:37:31 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void func()
{
	char *c = (char *)malloc(sizeof(char) * 5);
	c[0] = 'a';
	c[1] = 'b';
}

int	main(void)
{
	func();
	return (0);
}
