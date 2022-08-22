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
		if (!str)
			break ;
		free(str);
	}
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm -rf leaks_result_temp");
	return (0);
}