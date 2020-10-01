#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        
        int *data = (int *) malloc(100 * sizeof(int));
        
        free(data);
        
        printf("data[0] = %d\n", data[0]); // Wrong... Accessing data after freeing its memory
        
        return 0;
}
