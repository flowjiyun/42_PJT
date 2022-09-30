#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void MakeChild(int rval)
{
    pid_t cpid = fork();

    if(cpid == -1)
    {
        perror("error fork");
        return;
    }

    if(cpid>0)
    {
        printf("fork child pid:%u\n",cpid);
    }
    else
    {
        printf("pid:%d sleep %dseconds\n",getpid(), rval);
        sleep(rval);
	}
}

int main()
{
    srand((unsigned)time(0));

    int i = 0;
    for(i=0; i<5; i++)
    {
        MakeChild(rand()%10);
    }

    int rval=0;
    pid_t cpid=0;
    while(i>0)
    {
        cpid = wait(&rval);
        printf("cpid:%d exit status:%#x\n",cpid, rval);
        i--;
    }
    return 0;
}