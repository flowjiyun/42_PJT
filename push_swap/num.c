#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main() {

	int rotto[SIZE];
	int i,j;

	srand((unsigned)time(NULL));

	for (i = 0; i < SIZE; i++) {	// 로또번호 뽑기
		rotto[i] = (rand() % 45) + 1;
		for (j = 0; j < i; j++) {
			if (rotto[i] == rotto[j]) i--;
		}
	}

	printf("로또번호 생성기: \n");	// 출력
	for (i = 0; i < SIZE; i++) {
		printf("%d ",rotto[i]);
	}
	
	return 0;
}
