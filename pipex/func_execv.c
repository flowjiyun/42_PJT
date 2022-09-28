#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char *argv[] = {"./show_envp", "HTTP", NULL};
	char *envp[] = {"HTTP=badayak.com", NULL};

	execve("./show_envp", argv, envp);

	printf("에러");
	return (0);
}