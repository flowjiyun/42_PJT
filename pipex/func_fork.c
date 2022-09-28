#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int gv;
int main()
{
    int lv=0;

    gv=3, lv=2;
    printf("start... gv:%d lv:%d\n",gv,lv);
	int pd = getpid();
	printf("%d    ", pd);	
    pid_t cpid = fork();
    if(cpid == -1)
    {
        perror("error fork");
        return 1;
    }

    if(cpid>0)
    {
        gv++, lv++;
        printf("<parent> gv:%d lv:%d\n",gv,lv);
        printf("<parent> pid:%d ppid:%d\n", getpid(), getppid());
        sleep(1);
    }
    else
    {
        gv++, lv++;
        printf("<child> gv:%d lv:%d\n",gv,lv);
        printf("<child> pid:%d ppid:%d\n", getpid(), getppid());
    }
    return 0;
}