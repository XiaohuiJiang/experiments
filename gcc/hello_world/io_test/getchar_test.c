#include <stdio.h>

int main()
{
    int ch = -1;
    //printf("press any key to continue...\n");
    while((ch = getchar()) != EOF) putchar(ch);
    return 0;
}
