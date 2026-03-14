#include <stdio.h>

#define MAX_LINE 1000

int get_line(char a[], int max)
{
int i = 0;
char c;

    for(i=0; i<max && ((c=getchar()) != EOF) && c != '\n'; i++) {
        a[i] = c;
    }
    if(c == '\n') {
        a[i] = c;
        i++;
    }
    a[i] = '\0';

    return i;
}
int main()
{
int max =0, len=0;
char line[MAX_LINE];

    while((len = get_line(line, MAX_LINE)) > 0) {
        if(len > max)
            max = len;
    }

    if(max>0)
        printf("The longest line is: %d\n", max);

    return 0;
}
