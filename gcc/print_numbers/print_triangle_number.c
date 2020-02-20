/*************************************************************************
        > File Name: print_triangle_number.c
      > Author: Xiaohui Jiang
      > Mail: jiang_xiaohui@163.com 
      > Created Time: Thu Feb 20 18:37:53 2020
 ************************************************************************/

#include<stdio.h>

/*
 *print number of space
 */
void print_space(int number)
{
  int i=0;
  for(i=0; i<number; i++){
	  printf(" ");
  }
}

/*
 *print number with stars in middle
 *@s: start number
 *@e: end number
 *return next number of e
 */
int print_number_stars(int s, int e)
{
  int i=0;
  for(i=s; i<e; i++){
	  printf("%d * ", i);
  }
  printf("%d\n", e);

  return e+1;
}


int main()
{
  int h=0;
  int i=0;
  int n=1;

  while(1) {
    printf("Enter the height of the triangle (must be greater than 0): ");
    scanf("%d", &h);
	if (h<=0)
		printf("Invalid entry\n");
	else
		break;
  }

  printf(" "); //for the first line, make the number '1' in the middle of picture

  for(i=0; i<h; i++){
    print_space(h-1-i);
	n = print_number_stars(n,n+i);
  }

  printf("\n"); //the last empty line

  return 0;
}
