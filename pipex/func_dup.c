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

    fd = open("dup.txt", O_RDONLY);

    fd2 = dup(fd);
    // fd2 = dup2(fd, 5);
    memset(buf, 0x00, 80);
    read(fd, buf, 20);
    printf("fd : %d\n%s\n", fd, buf);

    memset(buf, 0x00, 80);
    read(fd2, buf, 20);
    printf("fd : %d\n%s\n", fd2, buf);

    close(fd);
}
