/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:14:30 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/28 17:19:08 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fds[2];
    int status;
    pid_t   child_pid;

    pipe(fds);
    printf("%d\n", fds[0]);
    printf("%d\n", fds[1]);

    child_pid = fork();

    char buf[100];
    if (child_pid > 0)
    {
  //      close(fds[1]);
        write(1, "sdfsadfs", 5);
        wait(&status);
        write(1, "@sdfsadfs", 5);
        printf("wake up...\n");

       // int fd = open("a.txt", O_CREAT | O_WRONLY);
        int rd =  read(fds[0], buf, 100);
        printf("rd : %d\n", rd);
        buf[rd] = '\0';
        printf("%s", buf);
        //write(fd, buf, rd);
    }
    else 
    {
        close(fds[0]);
        close(fds[1]);
       // dup2(fds[1], 1);
        sleep(1);
        char *cmd[] = {"ls", "-al", NULL};
        execve("/bin/ls", cmd, 0);
    }
}
