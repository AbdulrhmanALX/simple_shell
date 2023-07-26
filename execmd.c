#include "main.h"

void execmd(char **argv){
    char *command = NULL, *actual_command = NULL;
    pid_t child_pid;

    if (argv){
        command = argv[0];

        actual_command = get_location(command);

        child_pid = fork();

        if (child_pid < 0) {
            perror("Error:");
            return;
        }
        else if (child_pid == 0) {
           
            if (execve(actual_command, argv, NULL) == -1){
                perror("Error:");
            }
        }
        else {
           
            int status;
            wait(&status);
        }
    }
}
