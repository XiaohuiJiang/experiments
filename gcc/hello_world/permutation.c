#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>

int main()
{
    int i, j, k;
    int a, b, c;
    char stat[10] = {0,};

    for (i = 123; i < 329; i++){
        memset(stat, 0, sizeof(stat));
	a = i / 100;
	if ((a == 0) || (*(stat + a) > 0)) continue; else *(stat + a) = 1;
	b = (i % 100) / 10;
	if ((b == 0) || (*(stat + b) > 0)) continue; else *(stat + b) = 1;
	c = i % 10;
	if ((c == 0) || (*(stat + c) > 0)) continue; else *(stat + c) = 1;

	j = i * 2;
	k = i * 3;
	if (k > 987) continue;

	a = j / 100;
	if ((a == 0) || (*(stat + a) > 0)) continue; else *(stat + a) = 1;
	b = (j % 100) / 10;
	if ((b == 0) || (*(stat + b) > 0)) continue; else *(stat + b) = 1;
	c = j % 10;
	if ((c == 0) || (*(stat + c) > 0)) continue; else *(stat + c) = 1;

	a = k / 100;
	if ((a == 0) || (*(stat + a) > 0)) continue; else *(stat + a) = 1;
	b = (k % 100) / 10;
	if ((b == 0) || (*(stat + b) > 0)) continue; else *(stat + b) = 1;
	c = k % 10;
	if ((c == 0) || (*(stat + c) > 0)) continue; else *(stat + c) = 1;


	printf("%d %d %d\n", i, j, k);
    }
    return 0;
}
