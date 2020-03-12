#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int main()
{
    int i;
    int a, b, c;
    int m, n, t;

    scanf("%d %d %d", &a, &b, &c);

    printf("%2$.*1$lf\n", c, a*1.0/b);   //  Precision is given by next-parameter, see man printf for details

    //Decimal output
    m = a / b;
    printf("%d.", m);

    n = a % b;
    for (i=0; i<c-1; i++){
        t = n * 10 / b;
	printf("%d", t);
        n = n * 10 % b;
    }
    //handle the last number
    t = n * 10 / b;
    n = n * 10 % b;
    if (n * 10 / b >= 5)
        printf("%d", (t+1));
    else
	printf("%d", t);

    printf("\n");
    printf("time:%d seconds\n", clock()/CLOCKS_PER_SEC);
    return 0;
}
