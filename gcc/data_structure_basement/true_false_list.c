#include <stdio.h>


/* 打印n个bool变量list[i]到list[n]的所有的true/false排列
 */

void perm(int *list, int i, int n)
{
    int j, temp;
    if (i == n+1){
	for(j=0; j<=n; j++){
            printf("%c ", list[j]);
	}
	printf("\n");
    } else {
        list[i] = 'T';
	perm(list, i+1, n);
        list[i] = 'F';
	perm(list, i+1, n);
    }

}

int main()
{
    int list[] = {1, 2, 3};
    perm(list, 0, 2);
    return 0;
}
