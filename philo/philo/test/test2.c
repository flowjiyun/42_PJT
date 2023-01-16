#include <stdio.h>

int main(void)
{
	int a = 10;	
	unsigned int b = 10;
	unsigned int c = b * 0.8;
	unsigned int d = b * 8 / 10;

	printf("c : %u  d : %u\n", c, d);
}