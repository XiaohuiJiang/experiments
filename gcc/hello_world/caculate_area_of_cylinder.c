#include <stdio.h>
#include <math.h>

int main()
{
    const double pi = 4.0 * atan(1.0);
    double r, h, s1, s2, s;
    //scanf("%lf, %lf", &r, &h);  //input need be seperated by ','
    scanf("%lf %lf", &r, &h);     //input need be seperated by space only
    s1 = pi * r * r;
    s2 = 2 * pi * r * h;
    s  = 2.0 * s1 + s2;
    printf("Area = %.3lf\n", s);
    return 0;
}