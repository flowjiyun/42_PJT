/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:56:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/17 20:26:38 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"


int main()
{
   int      fd;
   char		*str;
   //ssize_t  rd_size;

fd = open("./test.txt", O_RDONLY);
str = get_next_line(fd);
printf("%s", str);
str = get_next_line(fd);
printf("%p", str);
return 0;
}
