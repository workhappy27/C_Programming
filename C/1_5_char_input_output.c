#include <stdio.h>

int main()
{
char c;

    c =  getchar();

    while(c != EOF) {
      putchar(c);
      c = getchar();
    }

    return 0;
}
/*
while((c = getchar()) != EOF)
    putchar(c);
    
To send an EOF signal from the keyboard:
🖥️  On Linux & macOS
Press:
CTRL + D
(Must be pressed on a new line, not immediately after a character.)

🪟 On Windows (PowerShell / CMD)
Press:
CTRL + Z, then press Enter
*/
