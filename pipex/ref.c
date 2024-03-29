#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	char *exec_argv2[] = {"grep", "hello", 0};
	char *exec_argv1[] = {"ls", "-al", 0};
	char *exec_argv3[] = {"ls", "-l", 0};
	char *exec_argv4[] = {"wc", "-l", 0};
	int fdin;
	int fdout;

	int cnt = -1;
	int fdpipe[2];
	int prev_pipe_in = -1;
	int curr_pipe_in;
	int curr_pipe_out;
	while (++cnt < 3)
	{
		printf("parent: fork()\n");
		if (cnt == 2)
			curr_pipe_out = open("outfile", O_CREAT | O_WRONLY | O_APPEND, 00666);
		else
		{
			pipe(fdpipe);
			curr_pipe_in = fdpipe[0];
			curr_pipe_out = fdpipe[1];
		}
		pid = fork();
		if (pid == 0)
		{
			if (cnt == 0)
			{
				prev_pipe_in = open("infile", O_RDONLY, 00666);
				if (prev_pipe_in == -1)
				{
					perror("open");
					exit(1);
				}
				dup2(prev_pipe_in, 0);
				close(prev_pipe_in);
				dup2(curr_pipe_out, 1);
				close(curr_pipe_out);
				close(curr_pipe_in);
		//		execve("/bin/ls", exec_argv1, 0);
				execve("/usr/bin/grep", exec_argv2, 0);
			}
			if (cnt == 1)
			{
				dup2(prev_pipe_in, 0);
				close(prev_pipe_in);
				dup2(curr_pipe_out, 1);
				close(curr_pipe_out);
				close(curr_pipe_in);
		//		execve("/bin/ls", exec_argv3, 0);
				execve("/usr/bin/grep", exec_argv2, 0);
			}
			if (cnt == 2)
			{
				dup2(prev_pipe_in, 0);
				close(prev_pipe_in);
				dup2(curr_pipe_out, 1);
				close(curr_pipe_out);
				close(curr_pipe_in);
		//		execve("/usr/bin/wc", exec_argv4, 0);
				execve("/usr/bin/grep", exec_argv2, 0);
			}
		}
		if (prev_pipe_in >= 0)
			close(prev_pipe_in);
		prev_pipe_in = curr_pipe_in;
		close(curr_pipe_out);
	}
	close(prev_pipe_in);
	waitpid(pid, NULL, 0);
}