#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	t_list a;
	t_list *b;
	printf("%lu\n", sizeof(b));
	printf("%lu\n", sizeof(a));
	printf("%lu\n", sizeof(a.content));
	printf("%lu\n", sizeof(a.next));
	return (0);
}