#include <stdio.h>
#include <string.h>

#define MAXLINES 10
#define MAXLEN 1000

/*
* The POSIX getline() prototype is:
*    ssize_t getline(char **lineptr, size_t *n, FILE *stream);
*
* when passed   nread = getline(line, &len, stdin);
* expected ‘char ** restrict’ but argument is of type ‘char *’
*   | extern __ssize_t getline (char **__restrict __lineptr,
*
*/
//char *lineptr[MAXLINES];
/* You cannot use getline() with a fixed array buffer.
* Below declaration is wrong, even though it works.
*/
char lineptr[MAXLEN];

int readlines(char *lineptr, int nlines)
{
//char *line= NULL;
size_t len = 0;
ssize_t nread = 0;

    nread = getline(&lineptr, &len, stdin);
    printf("%s\n", lineptr);

    return nread;

}

int main()
{
int nchar;

    nchar = readlines(lineptr, MAXLINES);

    printf("%d \n", nchar);
    return 0;
}
/*
i) char ** means:
    👉 an array of strings (char **argv)
    👉 dynamic 2D arrays of characters

    Ex: char **lines = malloc(10 * sizeof(char *));

ii) char *ptr[10];
    👉 an array of pointers to char

iii) char (*)[MAXLEN]
    👉 pointer to an array

iv) char * (*)[10]
    👉 Pointer to an array of 10 char*

*/
