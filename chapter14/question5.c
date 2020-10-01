#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        
        int *data = (int *) malloc(100 * sizeof(int));

        data[100] = 0; // Wrong... Buffer overflow!

        free(data);
        
        return 0;
}
