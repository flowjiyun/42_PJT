#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int i = 0;
	printf("%p\n", argv[argc]);
	while (argv[++i])
	{
		printf("%s\n", argv[i]);	
	}
	return (0);
}