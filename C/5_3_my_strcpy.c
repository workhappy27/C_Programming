include <stdio.h>

int my_strcpy1(char *s, char *t)
{
int i=0;

    while(t[i] != '\0') {
        s[i] = t[i];
        i++;
    }

    return 0;
}

int my_strcpy2(char *s, char *t)
{

    while((*s++ = *t++) != '\0');

   return 0;
}

int my_strcpy3(char *s, char *t)
{

    while(*s++ = *t++);

   return 0;
}

int my_strcpy4(char *s, char *t)
{

    while(*t != '\0') {
        *s++ = *t++;
    }

   return 0;
}

int main()
{
char s[20];
char *t = "C_Programming";

    my_strcpy1(s, t);
    printf("String: %s\n", s);

    my_strcpy2(s, t);
    printf("String: %s\n", s);

    my_strcpy3(s, t);
    printf("String: %s\n", s);

    my_strcpy4(s, t);
    printf("String: %s\n", s);

    return 0;
}
