#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	//char h[] = "hello";
	//char *n;
	char *s = ft_calloc(SIZE_MAX, SIZE_MAX);
	char *v = calloc(SIZE_MAX - 1, 1);
	printf("%p", s);
	printf("%p", v);
	return (0);
}