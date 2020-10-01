#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        
        int *x = (int *) calloc(1, sizeof(int));
        printf("Contents of *x = %d\n", *x); // should be 0 if we used calloc
        
        x = NULL;
        printf("Contents of *x = %d\n", *x); // segmentation fault
        
        free(x);
        
        return 0;
}
