#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

#define MB_TO_BYTES 1000000

int main(int argc, char *argv[]) {

        if (argc != 3) {
                printf("Wrong number of arguments. Program's usage: ./memory-user memory timeout\n");
                return 1;
        }

        char *p1, *p2;
        errno = 0; // not 'int errno', because the '#include' already defined it

        // Parse arguments
        long memory = strtol(argv[1], &p1, 10); // string to long(string, endpointer, base)
        long timeout = strtol(argv[2], &p2, 10);
        
        if (*p1 != '\0' || *p2 != '\0' || errno != 0) {
                printf("Error parsing the program's arguments.\n");
                return 1;
        }

        // Everything went well, allocate the array and loop 'timeout' seconds
        int *array = (int *) malloc(memory * MB_TO_BYTES);
        int i = 0;

        time_t start = time(NULL);
        time_t end = start + timeout;
        time_t elapsed = start;
        
        while (elapsed < end) {
                printf("Memory address of array[%d]: %p\n", i, &array[i]);
                elapsed = time(NULL);
                ++i;
        }

        free(array);
        
        return 0;
}
