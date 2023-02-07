/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:48:18 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/02/07 13:39:55 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"
typedef struct s_back
{
	int	w;
	int	h;
	char	c;
} t_back;

typedef struct s_circle
{
	char type;
	float x;
	float y;
	float r;
	char c;
}	t_circle;

int ft_strlen(char *str)
{
	int i ;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	argument_error(void)
{
	ft_putstr("arg error\n");
	return (1);
}

int	file_error(void)
{
	ft_putstr("file error\n");
	return (1);
}

void fill_back(char **map, t_back *back)
{
	for (int i = 0; i < back->h; ++i)
	{
		for (int j = 0; j < back->w; ++j)
			map[i][j] = back->c;
	}
}

void	print_map(char **map, t_back *back)
{
	for (int y = 0; y < back->h; ++y)
	{
		for (int x = 0; x < back->w; ++x)
			write(1, &map[y][x], 1);
		write(1, "\n", 1);
	}
}

int is_in_circle(int x, int y, t_circle *circle)
{
	float dist;

	dist = sqrtf(powf(x - circle->x, 2) + powf(y - circle->y, 2));
	if (dist > circle->r)
		return (0);
	if ((circle->r - dist) < (float)1)
		return (2);
	return (1);
}

void	paint(char **map, t_circle *circle, t_back *back)
{
	int ret;

	for (int y = 0; y < back->h; ++y)
	{
		for (int x = 0; x < back->w; ++x)
		{
			ret = is_in_circle(x, y, circle);
			if ((circle->type == 'c' && ret == 2) || (circle->type == 'C' && ret))
				map[y][x] = circle->c;
		}
	}
}

int	main(int argc, char **argv)
{
	t_circle	circle;
	t_back		back;
	FILE		*file;
	int			i, j, ret;
	char		**map;

	if (argc != 2)
		return (argument_error());
	file = fopen(argv[1], "r");
	if (file == NULL)
		return (file_error());
	if (fscanf(file, "%d %d %c\n", &back.w, &back.h, &back.c) != 3)
		return (file_error());
	if (!(back.w > 0 && back.w <= 300 && back.h > 0 && back.w <= 300))
		return (file_error());
	map = malloc(sizeof(char*) * back.h);
	if (map == NULL)
		return (1);
	for (int i = 0; i < back.h; ++i)
	{
		map[i] = malloc(sizeof(char) * back.w);
		if (map[i] == NULL)
			return (1);
	}
	fill_back(map, &back);
	while ((ret = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.r, &circle.c)) == 5)
	{
		printf("%c %f %f %f %c\n", circle.type, circle.x, circle.y, circle.r, circle.c);
		if (circle.r <= (float)0 || !(circle.type == 'c' || circle.type == 'C'))
			return (file_error());
		paint(map, &circle, &back);
	}
	if (ret != -1)
		return (file_error());
	print_map(map, &back);
	for (int i = 0; i < back.h; ++i)
	{
		free(map[i]);
	}
	free(map);
	fclose(file);
	return (0);
}
