#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

int	main(void)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		printf("%s", str);
		free(str);
		if (!str)
			break ;
	}	
	return (0);
}