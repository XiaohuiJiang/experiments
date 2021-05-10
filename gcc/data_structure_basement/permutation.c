#include <stdio.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = t)

void perm(char *list, int i, int n)
{/* generate all permutations of list[i] to list[n] */
	    
    int j, temp;
    if (i == n){
	for(j=0; j<=n; j++){
            printf("%c ", list[j]);
	}
	printf("    \n");
    } else {
    /* list[i] to list[n] has more than one permutations */
	for(j=i; j<=n; j++){
	    SWAP(list[i], list[j], temp);
	    perm(list, i+1, n);
	    SWAP(list[i], list[j], temp);
	}
    }

}

int main()
{
    char list[] = "abc";
    perm(list, 0, 2);
    return 0;
}
