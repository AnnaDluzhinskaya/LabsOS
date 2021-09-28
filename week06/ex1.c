#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int at[10];
int bt[10];

void getStr(char* line, int num){
    char s[2][128];

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 128; j++) {
        s[i][j] = NULL;
      }
    }

    int n = strlen(line);
    int k = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (line[i] != ',' && line[i] != '\n') {
            s[k][i-j] = line[i];
        } else {
            k++;
            j = i+1;
        }
    }
    at[num] = atoi(s[0]);
    bt[num] = atoi(s[1]);
}

void swap (int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void Sort(int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (at[j]>at[j+1]){
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
            }
        }
    }
}


int main() {

    FILE* stream = fopen("input.csv", "r");

    int n = 0;

    char line[256];

    while (fgets(line, 256, stream))
    {
        char* tmp = strdup(line);
        getStr(tmp, n++);
        free(tmp);
    }

    Sort(n);

    int ct = 0;
    float tat = 0,wt = 0;

    printf("\nP#\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0;i<n;i++){
        if (at[i]>ct){
            ct = at[i];
        }
        ct = ct+bt[i];
        tat = tat+(ct-at[i]);
        wt = wt+(ct-at[i]-bt[i]);
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),at[i],bt[i],ct,(ct-at[i]),(ct-at[i]-bt[i]));
    }
    printf("Average Turnaround time: %f\n",(tat/n));
    printf("Average waiting time %f\n",(wt/n));
}

