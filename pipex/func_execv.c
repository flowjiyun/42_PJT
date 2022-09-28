#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	for(int i = 0; envp[i]; i++)
		printf("%s\n", envp[i]);
	//char *argv[] = {"./show_envp", "HTTP", NULL};
	//char *envp[] = {"HTTP=badayak.com", NULL};

	//execve("./show_envp", argv, envp);

	printf("에러");
	return (0);
}