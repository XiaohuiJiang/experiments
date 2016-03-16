
#include <string.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    char   buf[16];
    size_t len = sizeof(buf);

    if (argc >= 2)
    {
        strncpy(buf, argv[1], len);
        buf[len-1] = '\0';
        printf("Your input is %s\n", buf);
        return 0;
    }
    else
    {
        printf("Not enough arguments.\n");
        return -1;
    }
}