#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int main() {
    int a, b;
    char str [256];

    printf("First number: ");

    fgets(str, 256, stdin);
    a = atoi(str);


    printf("Second number: ");
    fgets(str, 256, stdin);
    b = atoi(str);

    swap(&a,&b);

    printf("First number: %d\n",a);
    printf("Second number: %d\n",b);

}
