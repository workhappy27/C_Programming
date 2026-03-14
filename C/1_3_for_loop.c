#include <stdio.h>

int main() {
    int celsius;
    float fahrenheit;

    printf("Celsius  Fahrenheit\n");
    printf("--------------------\n");

    for (celsius = 0; celsius <= 100; celsius += 10) {
        fahrenheit = (9.0 / 5.0) * celsius + 32;
        printf("%7d %11.2f\n", celsius, fahrenheit);
    }

    return 0;
}
/*
* output:
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
