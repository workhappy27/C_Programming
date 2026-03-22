#include <stdio.h>

size_t my_strlen(const char s[])
{
size_t i = 0;

    while(s[i]!='\0')
        i++;

    return i;
}

int main()
{
const char string[]="HelloWorld";
size_t n=0;

    n = my_strlen(string);
    printf("The length of the string : %d\n", n);
    return 0;
}

/*
size_t is a typedef (alias) for an unsigned integer type that is guaranteed to
be able to represent the size of the largest possible object on the system.
*/
