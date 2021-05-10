#include <stdio.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = t)

/* from list[i] to list[n], calulate list[i] + (list[i+1]* x) + (list[i+2]*x^^2) +...+(list[n]*x^^(n-i))
 */

int horner(int *list, int i, int n, int x)
{
    int j, temp;
    if (i == n){
	return list[i];
    } else {
        return list[i] + x * horner(list, i+1, n, x);
    }

}

int main()
{
    int x = 2;
    int list[] = {1, 2, 3};
    int result = horner(list, 0, 2, x);
    printf("%d\n", result);
    return 0;
}
