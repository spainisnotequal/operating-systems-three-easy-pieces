#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main(int arg, char *argv[]) {

        char buffer[20];
        size_t nbytes;
        ssize_t bytes_written;
        
        int file_descriptor;
        int close_status;

        file_descriptor = open("bar.txt", O_WRONLY, 0);

        if (file_descriptor == -1) {
                fprintf(stderr, "error opening \"bar.txt\": %s\n", strerror(errno));
                exit(1);
        }

        pid_t process_id = fork();
        
        if (process_id < 0) {
                fprintf(stderr, "fork error: %s\n", strerror(errno));
                close_status = close(file_descriptor);
                if (close_status == -1) fprintf(stderr, "error closing the file\n");
                exit(1);
        } else if (process_id == 0) { /* Child */
                printf("child (pid:%d): file descriptor = %d\n", (int) getpid(), file_descriptor);
                
                strcpy(buffer, "Hello!\n");
                nbytes = strlen(buffer);
                bytes_written = write(file_descriptor, buffer, nbytes);

                close_status = close(file_descriptor);
                if (close_status == -1) printf("child (pid:%d): error closing the file\n", (int) getpid());
                exit(0);
        }

        /* Parent */
        wait(NULL);
        printf("parent (pid:%d): file descriptor = %d\n", (int) getpid(), file_descriptor);

        strcpy(buffer, "Goodbye!\n");
        nbytes = strlen(buffer);
        bytes_written = write(file_descriptor, buffer, nbytes);
                  
        close_status = close(file_descriptor);
        if (close_status == -1) printf("parent (pid:%d): error closing the file\n", (int) getpid());
        exit(0);
}
