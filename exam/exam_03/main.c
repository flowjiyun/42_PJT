/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:48:18 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/03 16:25:19 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_back
{
	int width;
	int height;
	char ch;	
}	t_back;

typedef struct s_circle
{
	char flag;
	float x;
	float y;
	float radius;
	char ch;
}	t_circle;

void read_file(FILE *file, t_back *back, t_circle *circle)
{
	fscanf(file, "%d %d %c\n", &(back->width), &(back->height), &(back->ch));
	fscanf(file, "%c %f %f %f %c", &(circle->flag), &(circle->x), &(circle->y), &(circle->radius), &(circle->ch));
}

int	main(int argc, char **argv)
{
	FILE *file;
	t_back back;
	t_circle circle;

	file = fopen(argv[1], "r");
	read_file(file, &back, &circle);
	printf("%d %d %c\n", back.width, back.height, back.ch);
	printf("%c %f %f %f %c\n", circle.flag, circle.x, circle.y, circle.radius, circle.ch);

	return (0);
}
