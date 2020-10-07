#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SECONDS_TO_NANOSECONDS 1e9

int main(int argc, char *argv[]) {
        
        unsigned long long diff;
        struct timespec start, end;

        /* measure monotonic time */
	clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
	sleep(1);	/* do stuff */
	clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

	diff = SECONDS_TO_NANOSECONDS * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed time = %llu nanoseconds\n", diff);

        /* now re-do this and measure CPU time; the time spent sleeping will not count (but there is a bit of overhead) */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);	/* mark start time */
	sleep(1);	/* do stuff */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);		/* mark the end time */

        diff = SECONDS_TO_NANOSECONDS * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed process CPU time = %llu nanoseconds\n", diff);
        
        return 0;
}
