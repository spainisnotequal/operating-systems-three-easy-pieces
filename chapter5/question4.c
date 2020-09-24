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
                printf("child (pid:%d)\n", (int) getpid());
                
                char *myargs[3];
                myargs[0] = strdup("ls"); // program: "ls" (list directory contents)
                myargs[1] = strdup(".");  // argument: directory to list
                myargs[2] = NULL;         // marks end of array

                execvp(myargs[0], myargs); // runs the list directory contents program
        }

        /* Parent */
        printf("parent (pid:%d)\n", (int) getpid());

        exit(0);
}
