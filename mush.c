#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    while (1)
    {
        printf("$ ");
        char test[2048];
        fgets(test, 2048, stdin);

        printf(test);
    }
}
