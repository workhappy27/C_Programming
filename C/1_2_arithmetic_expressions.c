
#include <stdio.h>

int main() {
    int fahr, celsius;
    int lower = 0;     // lower limit of temperature table
    int upper = 300;   // upper limit
    int step  = 20;    // step size

    printf("Fahrenheit  Celsius\n");
    printf("---------------------\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5 * (fahr - 32)) / 9;
        printf("%10d %8d\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

/*
* Fahrenheit is a temperature scale mainly used in the United States and a few other regions
* 32°F = freezing point of water
* 212°F = boiling point of water
* F → C:
* C= (5 × (F−32)) / 9
*
* Celsius, also known as the centigrade scale, is used in most of the world, including India
* 0°C = freezing point of water
* 100°C = boiling point of water
* C → F:
* F= (9/5)xC) + 32
*

output:
Fahrenheit  Celsius
---------------------
         0      -17
        20       -6
        40        4
        60       15
        80       26
       100       37
       120       48
       140       60
       160       71
       180       82
       200       93
       220      104
       240      115
       260      126
       280      137
       300      148
*
*/
