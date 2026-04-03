#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5
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
            return nlines;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
//        printf("%s\n", line);

    }

    return nlines;

}

void writelines(char **lineptr)
{
int i=0;

    for(i=0; i<MAXLINES; i++) {
        printf("%s", lineptr[i]);
    }

}
void swap(char **lineptr, int i, int j)
{
char *temp;

    temp = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = temp;

}

int partition(char **lineptr, int p, int r)
{
char *line;
int x, i, j, k;

//    printf("\n");
    printf("partition: p: %d, r:%d\n", p, r);
    line = lineptr[r];
    i = p-1;
    for (j=p; j<=r; j++) {
//        printf("line: %s, p: %d, i: %d, j: %d, r: %d\n", line, p, i, j, r);
        if (strcmp(lineptr[j], line) < 0) { /* conditional statement to compare char pointers */
//        if (lineptr[j] < x) { /* Conditional statement to compare integers */
            i++;
//            printf("swap(a[i]=%d,a[j]=%d): x: %d, p: %d, i: %d, j: %d, r: %d\n", lineptr[i], arr[j], line, p, i, j, r);
            swap(lineptr, i, j);
        }
    }
    swap(lineptr, i+1, r);

    writelines(lineptr);

//    printf("Return line: %s, p: %d, i: %d, j: %d, r: %d\n", line, p, i, j, r);
    return (i+1);
}

void quicksort(char **lineptr, int p, int r)
{
int q=0;
    if(p < r) {
        q = partition(lineptr, p, r);
        printf("q: %d\n", q);
        quicksort(lineptr, p, q-1);
        quicksort(lineptr, q+1, r);
    }

}
int main()
{
int nlines, p=0;

    nlines = readlines(lineptr);

    writelines(lineptr);

    quicksort(lineptr, p, MAXLINES-1);

    printf("Num of lines: %d and sorted array is:\n", nlines);
    writelines(lineptr);

    return 0;
}

/*
i) char ** means:
    👉 an lineptray of strings (char **argv)
    👉 dynamic 2D lineptrays of characters

    Ex: char **lines = malloc(10 * sizeof(char *));

ii) char *ptr[10];
    👉 an lineptray of pointers to char

iii) char (*)[MAXLEN]
    👉 pointer to an lineptray

iv) char * (*)[10]
    👉 Pointer to an lineptray of 10 char*

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
                                             
