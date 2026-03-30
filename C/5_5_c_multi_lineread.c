#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 2
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
char *lineptr[MAXLINES];

int readlines(char **lineptr)
{
char *line = NULL;
char *p;
size_t len = 0;
ssize_t nread = 0, nlines = 0;

    while(getline(&line, &len, stdin)) {

        p = malloc(len);

        if((p == NULL) || (nlines>=MAXLINES)) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
        printf("%s\n", line);

    }

    return nlines;

}

int main()
{
int nlines;

    nlines = readlines(lineptr);

    printf("%d \n", nlines);
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

Error: when declared char line[MAXLEN];
5_7_multi_lineread.c: In function ‘readlines’:
5_7_multi_lineread.c:26:19: warning: passing argument 1 of ‘getline’ from incompatible pointer type [-Wincompatible-pointer-types]
   26 |     while(getline(&line[0], &len, stdin)) {
      |                   ^~~~~~~~
      |                   |
      |                   char *
In file included from 5_7_multi_lineread.c:1:
/usr/include/stdio.h:645:45: note: expected ‘char ** restrict’ but argument is of type ‘char *’
  645 | extern __ssize_t getline (char **__restrict __lineptr,

Solution:
getline() must allocate memory itself when needed. For that:

        line must be a char * initialized to NULL`
        len must hold the allocated buffer size
*/
