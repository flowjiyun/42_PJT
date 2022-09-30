#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

// parent process save input / output and restore it at the end.
int	main(void)
{
	int	tmpin;
	int	tmpout;
	int command_num;

	// number of command from the parser
	command_num = 10;
	// save in/out
	tmpin = dup(0);
	tmpout = dup(1);

	// set the initial input
	// < infile
	int fdin;
	fdin = open("infile", O_CREAT | O_RDONLY);

	int ret;
	int fdout;
	int i;

	i = 0;
	while (i < command_num)
	{
		dup2(fdin, 0); // redirect input 
		close(fdin); // 0
		if (i == command_num - 1)
			fdout = open("outfile", O_CREAT | O_WRONLY);
		else
		{
			int fdpipe[2];
			pipe(fdpipe);
			fdout = fdpipe[1];
			fdin = fdpipe[0];
		}
		dup2(fdout, 1);
		close(fdout);

		ret = fork();
		//child
		if (ret == 0)
		{
			//execve(parsing argument);
		}	
		i++;
	}
	//restore in/out defaults
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	waitpid(ret, NULL);

	return (0);
}
