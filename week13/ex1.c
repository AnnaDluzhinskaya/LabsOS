#include <stdio.h>

#define RESOURCES 3
#define PROCESSES 5

int sum(int temp[], int n){
  int sum = 0;
  for (int i=0; i < n ; i++){
        sum+=temp[i];
  }
  return sum;
}

int main(void) {
  FILE *file;

  int C_matrix[PROCESSES][RESOURCES];
  int R_matrix[PROCESSES][RESOURCES];
  int E[RESOURCES];
  int A[RESOURCES];
  int R[RESOURCES];
  int finished[PROCESSES];
  int deadlock = 0;

  int temp;

  file = fopen("input_dl.txt", "r");

  while(!feof(file)){
      for (int i=0; i < RESOURCES ; i++){
        fscanf(file, "%d", &E[i]);
      }

      for (int i=0; i < RESOURCES ; i++){
        fscanf(file, "%d", &A[i]);
      }

      for (int i=0; i < PROCESSES ; i++){
        for (int j=0; j < RESOURCES ; j++){
            fscanf(file, "%d", &C_matrix[i][j]);
        }
      }

      for (int i=0; i < PROCESSES ; i++){
        for (int j=0; j < RESOURCES ; j++){
            fscanf(file, "%d", &R_matrix[i][j]);
        }
      }
  } 

  for (int i=0; i < RESOURCES ; i++){
        R[i]=A[i];
  }

  for (int i=0; i < PROCESSES ; i++){
        for (int j=0; j < RESOURCES ; j++){
             R[j]+=C_matrix[i][j];
        }
  }

  for (int i=0; i < PROCESSES ; i++){
        finished[i]=0;
  }
  int index = -1;

  if (E[0]>=R[0] && E[1]>=R[1] && E[2]>=R[2]){
    while (sum(finished,PROCESSES)<5 && deadlock==0){
      int loop_processes = 0;
      index = -1;
      for (int i=0; i < PROCESSES ; i++){
        int check = 0;
        if(finished[i]==0){
          for (int j=0; j < RESOURCES ; j++){
            if (A[j]<R_matrix[i][j]){
              check = 1;
            }
          }
          if (!check){
            finished[i]=1;
            loop_processes+=1;
            for (int j=0; j < RESOURCES ; j++){
              A[j]+=C_matrix[i][j];
            }
          }else{
            if (index==-1){
              index = i;
            }
          }
        }
      }
      if (sum(finished,PROCESSES)<5 && loop_processes == 0){
        deadlock = 1;
      }

    }

    if (deadlock==0){
      printf("OK!\n");
    }else{
      printf("Deadlock process - %d!\n", index);
    }
  }else{
    printf("Exception: not enoth resources!\n");
  }
   /*printf("%d %d %d\n\n", E[0], E[1], E[2]);
   printf("%d %d %d\n\n", A[0], A[1], A[2]);
  for (int i=0; i < PROCESSES ; i++){
      for (int j=0; j < RESOURCES ; j++){
          printf("%d ",  C_matrix[i][j]);
      }
      printf("\n");
    }

    printf("\n");

    for (int i=0; i < PROCESSES ; i++){
      for (int j=0; j < RESOURCES ; j++){
          printf("%d ",  R_matrix[i][j]);
      }
      printf("\n");
    }*/
}
