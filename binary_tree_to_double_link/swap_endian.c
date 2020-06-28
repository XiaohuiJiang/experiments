#include <stdio.h>
#include <arpa/inet.h>


int big_to_little(int i){
    int l = 0;
    l  = i>>24;
    l |= ((i)&0xff0000)>>8;
    l |= ((i)&0xff00)<<8;
    l |= ((i)&0xff)<<24;
    return l;
}

int swap_endian(int i){
    char *p = (char *)&i;
    char r[4] = {p[3],p[2],p[1],p[0]};
    int * t = (int*)r;
    return *t;
}

int main(){
    int i,l,m,n,o;
    scanf("%x", &i);
    printf("0x%x\n", i);
    l = big_to_little(i);
    m = htonl(i);
    n = ntohl(i);
    o = swap_endian(i);
    printf("0x%x\n",l);
    printf("0x%x\n",m);
    printf("0x%x\n",n);
    printf("0x%x\n",o);

    return 0;
}
