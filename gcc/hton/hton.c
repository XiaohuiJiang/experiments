
#include <stdio.h>

typedef unsigned int  uint32_t;
typedef unsigned char uint8_t;

uint32_t hton()
{
    uint32_t x = 0x12345678; // little endian
    uint32_t y = ((x & 0x000000ff) << 24)
               | ((x & 0xff000000) >>24)
               | ((x & 0x00ff0000) >> 8)
               | ((x & 0x0000ff00) << 8);

    printf("little endian 0x%x to network sequence is 0x%x\n", x, y);
    return y;
}

uint8_t get_bit(uint8_t x)
{
    uint8_t bitvec[10] = {0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa,
                          0x99, 0x88, 0x77, 0x66 };

    uint8_t byte   = x/8;
    uint8_t offset = x%8;

    return (bitvec[byte] & (1 << offset)) >> offset;
}

int main() {

    hton();

    for (int i = 0; i < 80; i++){
        printf("%d ", get_bit(i));
        if(i%8 == 7){
            printf("\n");
        }
    }
}
/* output
XIAOHUJI-M-L0GK:hton xiaohuji$ ./a.out 
little endian 0x12345678 to network sequence is 0x78563412
1 1 1 1 1 1 1 1 
0 1 1 1 0 1 1 1 
1 0 1 1 1 0 1 1 
0 0 1 1 0 0 1 1 
1 1 0 1 1 1 0 1 
0 1 0 1 0 1 0 1 
1 0 0 1 1 0 0 1 
0 0 0 1 0 0 0 1 
1 1 1 0 1 1 1 0 
0 1 1 0 0 1 1 0
*/
