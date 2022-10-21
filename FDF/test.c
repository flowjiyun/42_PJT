#include <stdio.h>

int	ft_atoi_short(char *str)
{
	int	val;
	int	sign;
	int	i;

	val = 0;
	sign = 1;
	i = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + str[i] - '0';
		i++;
	}
	return (val * sign);
}

int	ft_atoi_hex(char *str)
{
	int	val;
	int	i;

	val = 0;
	i = 2;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			val = val * 16 + str[i] - '0';
		else
			val = val * 16 + (str[i] - 'A' + 10);
		i++;
	}
	return (val);
}

int main(void)
{
	char *a = "-123";
	char *b = "0x00FF00";

	int c = ft_atoi_short(a);
	int d = ft_atoi_hex(b);

	printf("%d\n", c);
	printf("%d\n", 0x00FF00);
	printf("%d\n", d);
	return (0);
}
