#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

        // Array of 10 integers allocated dynamically
        int *x = (int *) malloc(10 * sizeof(int));
        printf("sizeof(x) = %zu (size of a pointer to an int)\n", sizeof(x));
        free(x);

        // Array of 10 integers allocated statically
        int y[10];
        printf("sizeof(y) = %zu (size of an array of 10 ints)\n", sizeof(y));

        // How to dinamycally allocate memory for strings
        char *src = "hola";
        char *dst = (char *) malloc(strlen(src) + 1);

        strcpy(dst, src); // copy the contents of src to dst
        printf("dst: %s\n", dst);

        free(dst);
        
        return 0;
}
