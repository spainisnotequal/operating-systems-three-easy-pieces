#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

#define SECONDS_TO_NANOSECONDS 1e9

int main(int argc, char *argv[]) {
        if (argc != 3) {
                printf("Wrong number of arguments. Program's usage: ./tlb pages trials\n");
                return 1;
        }

        /* Parse arguments */
        char *p1, *p2;
        errno = 0; // not 'int errno', because the '#include' already defined it

        int num_pages = (int)strtol(argv[1], &p1, 10); // string to long(string, endpointer, base)
        int num_trials = (int)strtol(argv[2], &p2, 10);
        int num_iterations = num_trials * num_pages;
        
        if (*p1 != '\0' || *p2 != '\0' || errno != 0) {
                printf("Error parsing the program's arguments.\n");
                return 1;
        }

        printf("Number of pages = %d\n", num_pages);
        printf("Number of trials = %d\n", num_trials);

        /* Allocate memory for the array */
        int page_size = getpagesize();
        printf("page size = %d\n", page_size);
        int jump = page_size / sizeof(int);
        
        int *a = (int *)calloc(num_pages * page_size, sizeof(int));

        /* Start timer */
        unsigned long long elapsed_time;
        struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);	// mark start time

        /* Access pages looping through an array */
        while (num_trials > 0) {
                for (int i = 0; i < num_pages * jump; i += jump) {
                        a[i] +=1;
                }
                --num_trials;
        }

        free(a); // Deallocate memory
        

        /* Stop timer and print results */        
	clock_gettime(CLOCK_MONOTONIC, &end);	// mark the end time
        
	elapsed_time = SECONDS_TO_NANOSECONDS * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
        printf("Elapsed time = %llu nanoseconds\n", elapsed_time / num_iterations);
        
        return 0;
}
