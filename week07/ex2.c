#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int n, temp;
    char str [256];

    printf("How many element do you want to have in array?\n");

    fgets(str, 256, stdin);
    n = atoi(str);

    int* arr = malloc (n* sizeof (int) );

    for(int i = 0;i<n;i++){
      arr[i]=i;
    }
    printf("Array: ");
    for(int i = 0;i<n;i++){
      printf("%d ",arr[i]);
    }
    free(arr);
}
