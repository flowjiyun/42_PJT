#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int idx = 0; idx < atoi(argv[1]); ++idx)
        printf("%d ", idx);
    printf("\n\n");
    for (int idx = atoi(argv[1]); idx > 0; --idx)
        printf("%d ", idx);
}
