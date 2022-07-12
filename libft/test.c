#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char a[3] = "aa";
	char b[5] = "ffff";

	printf("%lu",strlcpy(a, b, 3));
	printf("%lu", ft_strlcpy(a, b, 3));
	return (0);
}