#include <stdio.h>
#include "./libft/libft.h"

static int	check_digit(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i] != 0)
	{	
		j = 0;
		if (list[i][j] == '-' || list[i][j] == '+')
		{
			j++;
			if (list[i][j] == 0)
				return (0);
		}
		while (list[i][j] != 0)
		{
			if (list[i][j] >= '0' && list[i][j] <= '9')
			{
				j++;
				continue ;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static char	**check_valid_input(int argc, char **argv)
{
	int		i;
	char	**list;

	i = 0;
	while (i < argc)
	{
		list = ft_split(argv[i], ' ');
		if (check_digit(list) == 1)
		{
			i++;
			continue ;
		}
		else
			return (0);
	}
	return (list);
}

int	main(void)
{
	char	*str = "11 2- 35 21 ";
	if (check_valid_input(1, &str) > 0)
		printf("ok\n");
	else
		printf("Error\n");
	return (0);
}
