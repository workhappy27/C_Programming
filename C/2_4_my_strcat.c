#include <stdio.h>

void my_strcat(char *s, const char *t)
{
int i=0, j=0;

    while(s[i++] != '\0');

    i--;
    while(t[j] != '\0')
        s[i++] = t[j++];

    s[i] = '\0';
}

int main()
{
char s1[16] = "Wel";
const char *s2 = "come";

    my_strcat(s1,s2);
    printf("Concatenated string: %s\n", s1);
    return 0;
}

/*
* it’s good practice to mark the source string parameter as const char *t
* since you don’t modify it, and to ensure the destination buffer is large
* enough to hold the result.
*
* char *s1="Wel";
* "Wel" is string literals, typically stored in read‑only memory. Passing s1
* to my_strcat and writing into it causes undefined behavior.
* (usually a crash/segfault).
*
*/
