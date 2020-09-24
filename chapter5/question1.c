#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int arg, char *argv[]) {
        
        pid_t process_id = fork();
        int x = 1;
        
        if (process_id < 0) {
                fprintf(stderr, "fork error: %s\n", strerror(errno));
                exit(1);
        } else if (process_id == 0) { /* Child */
                printf("child (pid:%d): x = %d\n", (int) getpid(), ++x);
                exit(0);
        }

        /* Parent */
        printf("parent (pid:%d): x = %d\n", (int) getpid(), --x);
        exit(0);
}
