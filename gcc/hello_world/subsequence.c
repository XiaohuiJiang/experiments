#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int main()
{
    int i;
    int n, m;
    float h = 0.0;

    scanf("%d %d", &n, &m);

    for (i = n; i <= m; i++){
	h += (1.0/i) * (1.0/i);
    }
    printf("%.5lf\n", h);
    printf("time:%d seconds\n", clock()/CLOCKS_PER_SEC);
    return 0;
}
