
#include <string.h>
#include <stdio.h>

int i=1024;
int j;

int main(int argc, char * argv[])
{
    static int k = 256;
    static int l;

    printf("i=%d, at %p\n", i, &i);
    printf("j=%d, at %p\n", j, &j);
    printf("k=%d, at %p\n", k, &k);
    printf("l=%d, at %p\n", l, &l);

    char   buf[16] = "hello world\n";
    size_t len = strlen(buf);

    printf("len=%d, at %p\n", len, &len);
    printf("buf=%s, at %p\n", buf, &buf[0]);

    char * str = "HELLO WORLD\n";
    printf("str=%s, at %p\n", str, str);
    str[1] = 'g';

    return 0;
}
