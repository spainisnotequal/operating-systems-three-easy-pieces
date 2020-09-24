#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int arg, char *argv[]) {
        
        pid_t process_id;
        pid_t wait_process_id;

        process_id = fork();
        
        if (process_id < 0) {
                fprintf(stderr, "fork error: %s\n", strerror(errno));
                exit(1);
        } else if (process_id == 0) { /* Child */
                printf("child (pid:%d)\n", (int) getpid());
                exit(0);
        }

        /* Parent */
        wait_process_id = waitpid(-1, NULL, 0);
        if (wait_process_id > 0) {
                printf("child (pid:%d) terminated before parent (pid:%d)\n", wait_process_id, (int) getpid());
        }
        printf("parent (pid:%d)\n", (int) getpid());
        exit(0);
}
