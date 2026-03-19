#include <stdio.h>

int bitcount(int x)
{
int n;

    for(n=0; x!=0; x = x>>1) {
        if(x&1)
            n++;
    }
    return n;
}
int main()
{
int x = 0x3223;
int count;

    count = bitcount(x);
    printf("number: 0x%x bitcount: %d\n", x, count);
    return 0;
}
/*
number: 0x3223 bitcount: 6
*/
