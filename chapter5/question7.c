#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int arg, char *argv[]) {
        
        pid_t process_id = fork();
        
        if (process_id < 0) {
                fprintf(stderr, "fork error: %s\n", strerror(errno));
                exit(1);
        } else if (process_id == 0) { /* Child */
                close(STDOUT_FILENO);
                printf("child (pid:%d)\n", (int) getpid());
                exit(0);
        }

        /* Parent */
        printf("parent (pid:%d)\n", (int) getpid());
        exit(0);
}
