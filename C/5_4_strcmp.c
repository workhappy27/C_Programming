#include <stdio.h>

/*
* strcmp function to compare two input strings.
* return 0, when s[i] and t[i] is equal. Since, s[i]  - t[i] becomes zero.
*
* my_strcmp1("Cat", "Ca")   → 't' - '\0' → positive
* my_strcmp1("Ca", "Cat")   → '\0' - 't' → negative
*
*/

int my_strcmp1(char *s, char *t)
{
int i=0;

    while(s[i] != '\0' && t[i] != '\0') {
        if( s[i] != t[i])
            return s[i] - t[i];
        i++;
    }

    return s[i] - t[i];
}

int my_strcmp2(char *s, char *t)
{
int i=0;

    while(*s != '\0' && *t != '\0') {
        if( *s != *t)
            return *s - *t;
        s++; t++;
    }

    return *s - *t;
}


int main()
{
char s[20] = "C_Programming";
char *t = "C_Programming";
int res=0;

    res = my_strcmp1(s, t);
    if (res == 0)
        printf("string: %s is as same as %s\n", s, t);
    else
        printf("string: %s is not as same as %s\n", s, t);

    res = my_strcmp2(s, t);
    if (res == 0)
        printf("string: %s is as same as %s\n", s, t);
    else
        printf("string: %s is not as same as %s\n", s, t);

    return 0;
}
