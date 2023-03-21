#include "microshell.h"

//에러문 출력 함수
int print_error(char *str, char *value)
{
}

int main(int argc, char **argv, char **envp)
{
	int fd[2]; // 파이프 연결의 위한 pipe in out 변수
	int prev_pipe_in; // 이전 파이프 백업 용도
	int i;

	if (argc == 1) // 프로그램 인자로 아무것도 들어오지 않았을 때 종료
		return (1);
	i = 1;
	prev_pipe_in = -1;
	while (argv[i])
	{
		argv = &argv[i]; // cmd 시작 위치 초기화
		i = 0;
		// 구분자(|, ;, NULL)가 나올 때 까지 실제 cmd와 옵션 파싱 위한 i 값 갱신
		while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
			++i;
		// cd 빌트인 실행
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				print_error("argument number error", 0);
			else
			{
				if ()
			}

		}
		// cmd 다음이 | 로 구분지어질 경우 행동 (pipe 작업 등)
		else if (pipe)
		// cmd 다음이 ; 로 구분지어질 경우 행동 (명령어 실행 후 자식 프로세스 기다리기)
		else if  (;)

		++i;
			
	}
	return (0);
}