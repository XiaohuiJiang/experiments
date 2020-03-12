#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int main()
{
    long long i;
    long long n;

    scanf("%lld", &n);

    for (i = 1; i < n/2; i++){
	if (n%i == 0)
            printf("%lld, %lld, ", i, n/i);
	if (i * i >= n) break;
    }
    printf("\n%lf\n", clock()/CLOCKS_PER_SEC);
    return 0;
}
