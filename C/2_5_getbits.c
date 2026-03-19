#include <stdio.h>

/* getbits(x, 5, 3) return the bits at position 5, 4, 3 of x */
int getbits(int x, int p, int n)
{
    printf("0x%x\n", x);
    printf("0x%x, 0x%x\n", ~0, ~(~0<<n));
    printf("0x%x\n", (x>>(p+1-n)));
    printf("0x%x\n", (x>>(p+1-n))& ~(~0<<n));

//    x = (x >> (p+1-n)) & ~(~0<<n);
    return (x >> (p+1-n)) & ~(~0<<n);

}

int main()
{
int x = 2323, p = 5, n = 3;

    x = getbits(x, p, n);
    printf("The result: 0x%x\n", x);

    return 0;
}
/*
0x913
0xffffffff, 0x7
0x122
0x2
The result: 0x2
*/
