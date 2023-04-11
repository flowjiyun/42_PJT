#include "microshell.h"

int ft_strlen(char *str)
{
	int i;

	while (str[i])
		++i;
	return (i);
}
//에러문 출력 함수
int print_error(char *str, char *value)
{
	write(2, str, ft_strlen(str));
	if (value != 0)
		write(2, value, ft_strlen(value));
	write(2, "\n", 1);
	return (1);
}

int main(int argc, char **argv, char **envp)
{
	int fd[2]; // 파이프 연결의 위한 pipe in out 변수
	int prev_pipe_in; // 이전 파이프 백업 용도
	int i;

	if (argc == 1) // 프로그램 인자로 아무것도 들어오지 않았을 때 종료
		return (1);
	i = 1;
	prev_pipe_in = dup(0);
	//ex) ./microshell /bin/ls "|" /usr/bin/grep microshell ";" /usr/bin/echo hello
	// .      0 .         1     2            3               4        5 .       6

	while (argv[i])
	{
		argv = &argv[i]; // cmd 시작 위치 초기화 /bin/ls를  시작지점
		i = 0;
		// 구분자(|, ;, NULL)가 나올 때 까지 실제 cmd와 옵션 파싱 위한 i 값 갱신
		while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
			++i;
		// cd 빌트인 실행
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				print_error("error: cd: bad arguments", NULL);
			else
			{
				if (chdir(argv[1]) != 0)
					print_error("error: cd: cannot change directory to ", argv[1]);
			}

		}
		// cmd 다음이 | 로 구분지어질 경우 행동 (pipe 열고 fork 자식 : 프로세스 실행 , 부모 : 파이프 관리)
		else if (i != 0 && argv[i] != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0) // 자식 프로세스
			{
				dup2(fd[1], 1);
				dup2(prev_pipe_in, 0);
				close(prev_pipe_in);
				close(fd[0]);
				close(fd[1]);
				argv[i] = NULL;
				execve(argv[0], argv, envp);
				return (print_error("error: cannot execute ", argv[0]));
			}
			else // 부모 프로세스
			{
				close(fd[1]);
				close(prev_pipe_in);
				prev_pipe_in = fd[0];
			}
		}
		// cmd 다음이 ; or NULL 로 구분지어질 경우 행동 (자식 : 프로세스 실행, 부모 : 파이프 관리)
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0) // 자식 프로세스
			{
				dup2(prev_pipe_in, 0);
				close(prev_pipe_in);
				argv[i] = NULL;
				execve(argv[0], argv, envp);
				return (print_error("error: cannot execute ", argv[0]));
			}
			else // 부모 프로세스
			{
				close(prev_pipe_in);
				prev_pipe_in = dup(0);
				while (waitpid(-1, NULL, 0) != -1); // 모든 자식 프로세스 기다리기
			}
		}
		if (argv[i] != 0)
			++i;	
	}
	close(prev_pipe_in);
	return (0);
}