#include <stdio.h>

/* convert string into integer */
int my_atoi(char c[])
{
int int_value=0, n=0, base=1;

    while(c[n] != '\0') {
        if(c[n] >= '0' && c[n] <= '9') {
            n++;
        } else {
            printf("Invalid numeric string: non-digit '%c'\n", c[n]);
            int_value = -1;
            return int_value;
        }
    }

    n--;
    for(;n>=0; n--) {
        int_value = int_value + (c[n]-'0')*base;
        base = base*10;
        printf("c[n]: %d, int_value: %d, base: %d\n", c[n]-'0', int_value, base);
    }

    return int_value;
}

int main()
{
char c[] = {'1','2','3','4','\0'};
// const char *c = "1234";
int result=0;

    result = my_atoi(c);
    if(result != -1)
        printf("The result: %d\n", result);

    return 0;
}

/*
c[n]: 4, int_value: 4, base: 10
c[n]: 3, int_value: 34, base: 100
c[n]: 2, int_value: 234, base: 1000
c[n]: 1, int_value: 1234, base: 10000
The result: 1234
*/
