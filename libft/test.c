#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	printf("%d", atoi("9223372036854775808"));
	printf("%d", ft_atoi("9223372036854775808"));
	return (0);
}