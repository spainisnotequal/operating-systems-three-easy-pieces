#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        
        int *data = (int *) malloc(100 * sizeof(int));
        
        free(data + 1);
        
        return 0;
}
