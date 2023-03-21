#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();  // 자식 프로세스 생성

    if (pid == 0) {
        // 자식 프로세스 코드
        printf("Child process is running\n");
        kill(getpid(), SIGSTOP);  // 자식 프로세스를 SIGSTOP 신호로 일시 중지
        printf("Child process is running again\n");
        exit(0);
    }
    else if (pid > 0) {
        // 부모 프로세스 코드
        printf("Parent process is waiting for child to complete...\n");
        waitpid(pid, &status, WUNTRACED);  // 자식 프로세스 종료 또는 정지 대기

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status)) {
            printf("Child process terminated due to unhandled signal %d\n", WTERMSIG(status));
        }
        else if (WIFSTOPPED(status)) {
            printf("Child process stopped due to signal %d\n", WSTOPSIG(status));
            waitpid(pid, &status, 0);  // 자식 프로세스 종료 대기
        }
    }
    else {
        // fork() 실패
        printf("Failed to create child process\n");
        return 1;
    }

    return 0;
}

