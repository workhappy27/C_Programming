#include <stdio.h>

int my_strcmp1(char *s, char *t)
{
int i=0;

    while(t[i] != '\0') {
        if( s[i] == t[i]) {
            i++;
        } else {
            return -1;
            break;
        }
    }

    return 0;
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


    return 0;
}
