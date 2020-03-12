#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{
    int i, n;
    int count = 1;

    scanf("%d", &n);
    while (n /= 10){
        count++;
    }
    printf("%d\n", count);
    return 0;
}
