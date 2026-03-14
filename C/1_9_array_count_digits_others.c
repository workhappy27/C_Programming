#include <stdio.h>

/* count digits/integers, white space, others(alphabets, etc...) */

int main()
{
char c;
int count = 0, white_space = 0, others = 0;
int ndigits[10] = {0};

    while((c = getchar()) != EOF) {
        if(c == '\n' || c == '\t' || c == ' ')
            white_space++;
        else if (c>='0' && c<='9')
            ndigits[c-'0']++;
        else
            others++;
    }
    printf("The output: \n");
    for(count=0; count<=9; count++)
        printf("%d ", ndigits[count]);
    printf("no of white spaces are: %d and others: %d\n", white_space, others);

    return 0;
}
/*
2
1
The number of characters received are: 4

To send an EOF signal from the keyboard:
🖥️  On Linux & macOS
Press:
CTRL + D
(Must be pressed on a new line, not immediately after a character.)

🪟 On Windows (PowerShell / CMD)
Press:
CTRL + Z, then press Enter
*/
