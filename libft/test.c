#include <stdio.h>
#include <string.h>
#include "libft.h"
int	main(void)
{
	printf("%d", ft_strncmp("test", "testss", 7));
	printf("\n");
	printf("%d", strncmp("test", "testss", 7));
	printf("\n");
	printf("%d", ft_strncmp("testss", "test", 7));
	printf("\n");
	printf("%d", strncmp("testss", "test", 7));
	printf("\n");
	printf("%d", ft_strncmp("test\200", "test\0", 6));
	printf("\n");
	printf("%d", strncmp("test\200", "test\0", 6));
	printf("\n");

	printf("%d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
	printf("%d\n", strncmp("abcdefgh", "abcdwxyz", 4));
	printf("%d\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("%d\n", strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("%d\n", ft_strncmp("abcdefgh", "", 0));
	printf("%d\n", strncmp("abcdefgh", "", 0));

	return (0);
}