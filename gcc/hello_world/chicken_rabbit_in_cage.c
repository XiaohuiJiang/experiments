#include <stdio.h>

int main()
{
    int chicken, rabbits, heads, legs;
    scanf("%d%d", &heads, &legs);
    chicken = (4 * heads - legs) / 2;
    rabbits = heads - chicken;
    if (((legs % 2) == 1) || (chicken < 0) || (rabbits < 0))
	printf("No answer\n");
    else
        printf("%d %d\n", chicken, rabbits);
    return 0;
}
