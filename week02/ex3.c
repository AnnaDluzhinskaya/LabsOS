#include <stdio.h>
#include <stdlib.h>
void f (int n){
    for (int i = 0; i < n; i++){
        for (int j = 1; j < n - i; j++){
            printf(" ");
        }

        for (int j = n - i*2; j <= n; j++){
            printf("*");
        }

        printf("\n");
    }
}

void f1 (int n){
    for (int i = 1; i <=n ; i++){
        for (int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
}

void f2 (int n){
    int k = 1;
    int m = 1;
    for (int i = 1; i <=n ; i++){
        for (int j = 0; j < k; j++){
            printf("*");
        }
        if (m<=n/2){
            k++;
            m++;
        }else{
            k--;
            m++;
        }
        printf("\n");
    }
}

void f3 (int n){
    for (int i = 1; i <=n ; i++){
        for (int j = 0; j < 7; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main() {

    printf("Choose the number for triangle: ");

    int n, temp;
    char str [256];
    fgets(str, 256, stdin);
    n = atoi(str);
    f(n);

    printf("Choose the another option (1, 2 or 3): ");

    fgets(str, 256, stdin);
    temp = atoi(str);

    if (temp==1){
        f1(n);
    }else if (temp==2){
        f2(n);
    }else if (temp==3){
        f3(n);
    }else{
        printf("There is no such option!");
    }
}
