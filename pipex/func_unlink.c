#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	int ret;
	char buf[10] = "hello";

	fd = open("demo", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
	{
		perror("error open");
		return (1);
	}
	unlink("demo");
	ret = write(fd, buf, 10);

	if (ret == 10)
		printf("write ok\n");
	else
		printf("write fail\n");
	close(fd);

	return (0);
}