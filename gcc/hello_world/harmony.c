#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int main()
{
    int i;
    int n;
    float h = 0.0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++){
	h += 1.0/i;
    }
    printf("%lf\n", h);
    printf("time:%d seconds\n", clock()/CLOCKS_PER_SEC);
    return 0;
}
