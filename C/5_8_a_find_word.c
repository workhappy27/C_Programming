include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/*
*
* The POSIX getline() prototype is:
*    ssize_t getline(char **lineptr, size_t *n, FILE *stream);
*
* The first optional argument is argv[1] and the last is argv[argc-1];
* additionally, the standard requires that argv[argc] be a null pointer.
*/

/*
* find: print lines that match pattern from 1st arg
*/

int pattern_match(char *pattern)
{
char *line;
size_t len = 0;
int pattern_found=0;


    printf("pattern to be found: %s\n", pattern);

    while(getline(&line, &len, stdin) > 0) {
        if(strstr(line, pattern) != NULL) {
            printf("%s\n", line);
            pattern_found++;
            printf("No of pattern_found: %d\n", pattern_found);
        }
    }

    return pattern_found;
}

int main(int argc, char *argv[])
{
int pattern_found=0;


    if(argc!=2) {
        printf("Usuage: find %s <pattern>\n", argv[0]);
        return -1;
    }

    printf("pattern to be found: %s\n", argv[1]);
    pattern_found = pattern_match(argv[1]);

    printf("No of pattern_found: %d\n", pattern_found);

    return 0;
}
/*
* size_t is an unsigned integer type
* int is a signed integer type
*
*/
