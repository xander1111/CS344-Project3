#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    while (1)
    {
        printf("$ ");
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

        execvp(args[0], args);
    }
}
