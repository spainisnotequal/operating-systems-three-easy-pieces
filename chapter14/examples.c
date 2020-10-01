#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

        // Array of 10 integers allocated dynamically
        int *x = (int *) malloc(10 * sizeof(int));
        printf("sizeof(x) = %zu (size of a pointer to an int)\n", sizeof(x));

        // Array of 10 integers allocated statically
        int y[10];
        printf("sizeof(y) = %zu (size of an array of 10 ints)\n", sizeof(y));

        
        return 0;
}
