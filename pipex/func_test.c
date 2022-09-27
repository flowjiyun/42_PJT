#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int fd, fd2;
    char buf[80];

    fd = open("dup.c", O_RDONLY);

    memset(buf, 0x00, 80);
    read(fd, buf, 20);
    printf("fd : %d\n%s\n", fd, buf);

    fd2 = dup(fd);
    memset(buf, 0x00, 80);
    read(fd2, buf, 20);
    printf("fd : %d\n%s\n", fd2, buf);

    close(fd);
}
