#include <stdio.h>
#include <math.h>
#include <limits.h>

void hanxin(int a, int b, int c, FILE * fout)
{
    int i;

    for (i = 10; i <= 100; i++){
	if ((i%7 == c) && (i%5 == b) && (i%3 ==a)){
	    fprintf(fout, "%d %d %d %d\n", a, b, c, i);
	    return;
	}
    }
    fprintf(fout, "%d %d %d %s\n", a, b, c, "no answer");
}

void hanxin_2(int a, int b, int c, FILE * fout)
{
    int i;

    for (i = 7+c; i <= 100; i += 7){
	if (i < 10) continue;
	if ((i%5 == b) && (i%3 ==a)){
	    fprintf(fout, "%d %d %d %d\n", a, b, c, i);
	    return;
	}
    }
    fprintf(fout, "%d %d %d %s\n", a, b, c, "no answer");
}


int main()
{
    int t;
    int a, b, c;

    FILE * fout = fopen("hanxin.out", "wb");

    for (a = 0; a < 3; a++){
    for (b = 0; b < 5; b++){
    for (c = 0; c < 7; c++){
        hanxin_2(a, b, c, fout);
    }}}
    fclose(fout);
    return 0;
}
