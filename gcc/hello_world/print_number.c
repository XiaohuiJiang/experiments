#include<stdio.h>

void print_2(char val)
{
    for (int i = 7; i >= 0; i--){
	if(val & (1 << i))
	    printf("1");
	else
	    printf("0");
    }
    printf(" ");
}

void bin_out(void* p_i, size_t len)
{
    unsigned char * p_c = (char*)p_i;
    printf("\nbase 10:");
    for (int i = 0; i < len; i++){
        printf("%d ", *(p_c+i));
    }
    printf("\nbase 16:");
    for (int i = 0; i < len; i++){
        printf("0x%02x ", *(p_c+i));
    }
    printf("\nbase  2:");
    for (int i = 0; i < len; i++){
        print_2(*(p_c+i));
    }
    printf("\n");
}


int main()
{
  int   a = 8/5;
  float b = 8.0/5;
  double c = 8.0/5;

  printf("\nhello int:\n");
  printf("%d\n", a);
  printf("%e\n", a);
  printf("%f\n", a);
  printf("%lf\n", a);
  printf("%.1lf\n", a);
  printf("%.2lf\n", a);
  bin_out(&a, sizeof(int));

  printf("\nhello float:\n");
  printf("%d\n", b);
  printf("%e\n", b);
  printf("%f\n", b);
  printf("%lf\n", b);
  printf("%.1lf\n", b);
  printf("%.2lf\n", b);
  bin_out(&b, sizeof(float));

  printf("\nhello double:\n");
  printf("%d\n", c);
  printf("%e\n", c);
  printf("%f\n", c);
  printf("%lf\n", c);
  printf("%.1lf\n", c);
  printf("%.2lf\n", c);
  bin_out(&c, sizeof(double));


  return 0;
}
