#include <stdio.h>

#define WORD_IN 1
#define WORD_OUT 0

int main()
{
char c;
int state = WORD_OUT, count = 0;

    while((c = getchar()) != EOF) {
        if(c == '\n' || c == ' ' || c == '\t'|| c == '\r') {
            state = WORD_OUT;
        } else if (state == WORD_OUT) {
            state = WORD_IN;
            count++;
        }

    }
    printf("The number of words received are: %d\n", count);

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
