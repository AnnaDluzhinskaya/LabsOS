#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main() {
    while (1) {
        char str[256];
        fgets(str, 256, stdin);

        char *temp = strtok(str, " ");
        char *arr[10];

        int i = 0;

        while (temp != NULL) {
            arr[i] = temp;
            i++;
            temp = strtok(NULL, " ");
        }
        arr[i] = NULL;

        if (arr[i - 1][strlen(arr[i - 1]) - 1] == '\n') {
            arr[i - 1][strlen(arr[i - 1]) - 1] = '\0';
        }

        char *result = malloc(5 + strlen(arr[0]));
        strcat(result, "/bin/");
        strcat(result, arr[0]);

        int p[2];
        if (pipe(p) == -1)
            exit(1);

        int pid = fork();
        int is_BG = 0;
        if (strcmp(arr[i - 1], "&") == 0) {
            is_BG = 1;
        }

        if (pid == 0) {
            close(p[0]);
            dup2(p[1], 1);
            dup2(p[1], 2);
            close(p[1]);
            execve(result, arr, NULL);
            exit(0);
        } else {
            if (is_BG == 1) {
                close(p[1]);
                close(p[0]);
            } else {
                waitpid(pid, NULL, WUNTRACED);
                close(p[1]);

                char output[1024] = "";
                while (read(p[0], output, sizeof(output)) != 0)
                    printf(output);

                if (output[strlen(output) - 1] != '\n')
                    printf("\n");
                close(p[0]);
            }
        }
    }
}
