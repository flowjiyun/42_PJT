#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (1 < argc)
	{
		printf("환경 변수 %s는 %s\n", argv[1], getenv(argv[1]));
	}
	else
		printf("실행 방법 : show_envp [환경변수]\n");
	return (0);
}