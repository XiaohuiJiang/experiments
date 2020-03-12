#include <stdio.h>
#include <math.h>
#include <limits.h>


int main()
{
    int i;
    int h, t, m;

    FILE * fout = fopen("daffodil.out", "wb");

    for (i = 100; i <= 999; i++){
	h = i / 100;
	t = (i % 100) / 10;
	m = i % 10;
        if (i == (h*h*h + t*t*t + m*m*m)){
	    fprintf(fout, "%d\n", i);
	}
    }
    fclose(fout);
    return 0;
}
