#include <stdio.h>

int main()
{
char c;
int count = 0;

    while((c = getchar()) != EOF) {
       if(c == '\n')
            count++;
    }
    printf("The number of lines received are: %d\n", count);

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
