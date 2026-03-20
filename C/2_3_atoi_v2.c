#include <stdio.h>
#include <ctype.h>

/* Standard char string to integer conversion from left to right */
int atoi(const char *s)
{
int n = 0, i=0, sign;

    for(i=0; isspace(s[i]); i++) { /* skip white space */
        printf("space at pos: %d\t", i);
    }
    if (i!=0)
        printf("\n");

    sign = (s[i] == '-') ? -1 : 1; /* Assign sign */

    if(s[i] == '-' || s[i] == '+') { /* skip sign */
        printf("sign: %c\n", s[i]);
        i++;
    }

    for(;s[i] >= '0' && s[i] <= '9';i++)
        n = n*10+(s[i]-'0');

    return (sign*n);
}


int main()
{
const char *s = "-1234";
int res=0;

    res = atoi(s);
    printf("The result: %d\n", res);
}
/*
1.
In general, isspace(int c) returns non‑zero (true) if c is one of the standard whitespace characters:

space: ' '
horizontal tab: '\t'
newline: '\n'
vertical tab: '\v'
form feed: '\f'
carriage return: '\r'

2.
In this program, the loop continues only while current char is whitespace:
The loop condition isspace(s[i]) is checked before each iteration:

If s[i] is whitespace, the loop body runs, and then i++ moves to the next character.
If s[i] is not whitespace, the condition fails and the loop stops immediately.

3.
for rubust handling use strtol()
*/
