#include <stdio.h>

int main()
{
    int i = 0;
    printf("2 + 3  =  %d\n", 2+3);
    printf("2 || 3 =  %d\n", 2||3);
    printf("2 && 3 =  %d\n", 2&&3);
    printf("2 || i++ =  %d, i = %d\n", 2||i++, i);
    printf("2 && i++ =  %d, i = %d\n", 2&&i++, i);
    0 && printf("i = %d @%d\n", ++i, __LINE__);
    1 && printf("i = %d @%d\n", ++i, __LINE__);
    1 || printf("i = %d @%d\n", ++i, __LINE__);
    0 || printf("i = %d @%d\n", ++i, __LINE__);
    return 0;
}
