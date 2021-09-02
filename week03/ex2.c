#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void BubbleSort(int * arr, int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main() {
    int n, temp;
    char str [256];

    printf("How many element do you want to have in array?\n");

    fgets(str, 256, stdin);
    n = atoi(str);
    int arr[n];

    printf("Enter %d numbers: \n",n);
    for (int i = 0; i < n ;i++){
        fgets(str, 256, stdin);
        temp = atoi(str);
        arr[i] = temp;
    }

    BubbleSort(&arr,n);

    printf("Sorted array: \n");

    for (int i = 0; i < n ;i++){
        printf("%d ", arr[i]);
    }
}
