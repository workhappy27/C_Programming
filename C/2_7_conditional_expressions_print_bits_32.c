#include <stdio.h>
#include <stdint.h>

void print_bits_32(uint32_t x)
{
int i;
    for(i=31; i>=0; i--)
        putchar((x & (1<<i)) ? '1' : '0' );

    printf("\n");
}

int main()
{
uint32_t x = 0x12341234;

    print_bits_32(x);

    return 0;
}
/*
00010010001101000001001000110100
*/
