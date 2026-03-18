#include <stdio.h>

/* Standard char string to integer conversion from left to right */
int atoi(char *s)
{
int n = 0, i;

    for(i=0; s[i] >= '0' && s[i] <= '9';i++)
        n = n*10+(s[i]-'0');

    return n;
}


int main()
{
char *s = "1234";
int res=0;

    res = atoi(s);
    printf("The result: %d\n", res);
}
/*
The result: 1234
*/
