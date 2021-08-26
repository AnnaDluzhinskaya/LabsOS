#include <stdio.h>
#include <string.h>

int main() {
    printf("Write a string: ");
    char line[256];
    fgets(line,256,stdin);
    unsigned long length = strlen(line);

    char symbol;
    for (int i = 0; i < length/2; i++){
        symbol = line[i];
        line[i] = line[length-i-1];
        line[length-i-1] = symbol;
    }

    printf("New string: %s", line);
}
