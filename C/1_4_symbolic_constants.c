#include <stdio.h>

/* A #define line defines a symbolic constant to be a particular string of characters */

#include <stdio.h>

#define MIN_C   0      // start value (Celsius)
#define MAX_C   100    // end value   (symbolic constant used in loop condition)
#define STEP_C  10     // step size

int main(void) {
    int celsius;
    float fahrenheit;

    printf("Celsius  Fahrenheit\n");
    printf("--------------------\n");

    for (celsius = MIN_C; celsius <= MAX_C; celsius += STEP_C) {
        fahrenheit = (9.0f / 5.0f) * celsius + 32.0f;
        printf("%7d %11.2f\n", celsius, fahrenheit);
    }

    return 0;
}
/*
* ./a.out
Celsius  Fahrenheit
--------------------
      0       32.00
     10       50.00
     20       68.00
     30       86.00
     40      104.00
     50      122.00
     60      140.00
     70      158.00
     80      176.00
     90      194.00
    100      212.00
*/
