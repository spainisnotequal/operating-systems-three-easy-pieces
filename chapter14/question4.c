#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        
        int *x = (int *) calloc(1, sizeof(int));

        // free(x); // we forget to free the memory
        
        return 0;
}
