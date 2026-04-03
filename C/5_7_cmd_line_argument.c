#include <stdio.h>
/*
* The first optional argument is argv[1] and the last is argv[argc-1];
* additionally, the standard requires that argv[argc] be a null pointer.
*/
int main(int argc, char *argv[])
{

     while(argc>0) {
//         printf("%s\n", argv[argc]); /* Out of bound access */
         printf("%s\n", argv[argc-1]);
         argc--;
     }

    return 0;
}
/*
out
this
Check
./a.out <- Name by which the program was invoked.

*/
