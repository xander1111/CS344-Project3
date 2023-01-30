#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int run_command(char* args[]) {
    if (strcmp(args[0], "cd") == 0) {
        if (chdir(args[1]) == -1) {
            perror("");
            return -1;
        }
        else return 0;
    }
    else if (strcmp(args[0], "exit") == 0) exit(0);

    int pid = fork();
    if (pid == 0)
    {
        execvp(args[0], args);

        perror("Error running program");
        exit(1);
    }

    wait(NULL);
    return 0;
}

int main(void) {
    while (1)
    {
        printf("$ ");
        fflush(stdout);

        char input[2048];
        fgets(input, 2048, stdin);

        char* args[128];
        char* arg = strtok(input, " \n");
        args[0] = arg;

        for (int i = 1; arg != NULL; i++)
        {
            arg = strtok(NULL, " \n");
            args[i] = arg;
        }

        run_command(args);
    }
}
