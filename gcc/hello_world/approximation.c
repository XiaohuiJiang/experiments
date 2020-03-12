#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int main()
{
    int i;
    float n;
    float h = 0.0;


    for (i = 1; ; i++){
	n = 1.0/(2 * i - 1);
	if (n < 0.000001) break;
	if (i%2 == 1)
	    h += n;
	else
	    h -= n;
    }
    printf("%lf\n", h);
    printf("time:%d seconds\n", clock()/CLOCKS_PER_SEC);
    return 0;
}
