#include <stdio.h>
#include <stdlib.h>

struct check {
	int a;
	int b;
	char str[4];
	int c;
} ;

int main()
{

    printf("The offset addr of struct member a: %pK\n", &((struct check*)0)->a);
    printf("The offset addr of struct member b: %pK\n", &((struct check*)0)->b);
    printf("The offset addr of struct member str: %pK\n", &((struct check*)0)->str);
    printf("The offset addr of struct member c: %pK\n", &((struct check*)0)->c);
	
    return 1;
}
