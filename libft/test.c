#include <stdio.h>
#include <string.h>
#include "libft.h"
int	main(void)
{
	char	set [] = "\t \n";

	char	s1[] = "          ";
	printf("%s", ft_strtrim(s1, set));
	return (0);
}