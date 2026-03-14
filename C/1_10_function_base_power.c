#include <stdio.h>

/* Test power function, 'base' to the power 'n'. */

long power(int base, int n)
{
long p = 1;
int i = 0;

    for(i=0; i<=n; i++)
        p = p * base;

    return p;
}

int main()
{
int i;

    for(i=0; i<10; i++) {
        printf("%d^%d is: %ld\n", 2, i, power(2,i));
        printf("%d^%d is: %ld\n", -3, i, power(-3,i));
    }
    return 0;
}
/*
2^0 is: 2
-3^0 is: -3
2^1 is: 4
-3^1 is: 9
2^2 is: 8
-3^2 is: -27
2^3 is: 16
-3^3 is: 81
2^4 is: 32
-3^4 is: -243
2^5 is: 64
-3^5 is: 729
2^6 is: 128
-3^6 is: -2187
2^7 is: 256
-3^7 is: 6561
2^8 is: 512
-3^8 is: -19683
2^9 is: 1024
-3^9 is: 59049
*/
