#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node{
    int value;
    struct Node *next;
};


struct List {
    struct Node *head;
    struct Node *tail;
    int numberOfElements;
};

void delete_node(struct List *list, int index){
    if (index == 0){
        struct Node *temp, *used;
        used = list->head;
        temp = used -> next;
        memset(used, 0, sizeof(struct Node));
        list->head = NULL;
        list->head = temp;
        list->numberOfElements-=1;
    }else if (list->numberOfElements>index){
        struct Node *tempFirst;
        struct Node *tempLast;
        tempFirst = list->head;
        for (int i = 0; i < index-1; i++){
            tempFirst = tempFirst -> next;
        }
        tempLast = tempFirst -> next;
        tempFirst -> next = tempLast -> next;
        memset(tempLast, 0, sizeof(struct Node));
        if (index == list->numberOfElements - 1){
            list->tail = tempFirst;
        }
        list->numberOfElements-=1;
    }
}
void insert_first(struct List *list, int item){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = item;

    if (list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    }else{
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->numberOfElements+=1;
}

void insert_node(struct List *list,  int item, int index){
    if (index == 0){
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->value = item;

        if (list->head == NULL){
            list->head = newNode;
            list->tail = newNode;
        }else{
            list->tail->next = newNode;
            list->tail = newNode;
        }
        list->numberOfElements+=1;
    }else if (index == list->numberOfElements){
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode -> value = item;

        if (list->head == NULL){
            list->head = newNode;
            list->tail = newNode;
        }else{
            list->tail->next = newNode;
            list->tail = newNode;
        }
        list->numberOfElements+=1;
    }else{
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode -> value = item;

        struct Node *temp;
        temp = list->head;
        for (int i = 0; i < index-1; i++){
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
        list->numberOfElements+=1;
    }

}

void print_list(struct List *list){
    if (list->numberOfElements==0){
        printf("There are no elements in list!\n");
    }else {
        printf("List of elements: ");
        struct Node *temp = list->head;
        for (int i = 0; i < list->numberOfElements; i++) {
            printf("%d ", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

int getFirst(struct List *list){
    struct Node *temp = list -> head;
    return(temp -> value);
}

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


int main(int argc, char *argv[]) {

    int quantum = atoi(argv[1]);

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
    int ct_arr[n];
    int temp_bt[n];

    for(int i = 0;i<n;i++){
      temp_bt[i]=bt[i];
    }

    struct List list;// Create linked list
    list.numberOfElements = 0;
    list.head = NULL;
    list.tail = NULL;
    int time_now = at[0];
    int ind = 0;

    int tempInd = list.numberOfElements;
    
    while(time_now==at[ind]){
      insert_node(&list,ind,tempInd);
      ind++;
    }
  
    int cnt = 0;
    while(cnt<n){
      if (list.numberOfElements!=0){
        if (temp_bt[getFirst(&list)]<=quantum){
          for (int i = 0; i < temp_bt[getFirst(&list)]; i++){
            time_now++;
            while(time_now==at[ind]){
              insert_node(&list,ind,list.numberOfElements);
              ind++;
              if (ind > n-1) {
                break;
              }
            }
          }
          temp_bt[getFirst(&list)]=0;
          ct_arr[getFirst(&list)]=time_now;
          delete_node(&list,0);
          cnt++;
        }else{
          for (int i = 0; i < quantum; i++){
            time_now++;
            while(time_now==at[ind]){
              insert_node(&list,ind,list.numberOfElements);
              ind++;
              if (ind > n-1) {
                break;
              }
            }
          }
          temp_bt[getFirst(&list)]=temp_bt[getFirst(&list)]-quantum;
          int temp = getFirst(&list);
          delete_node(&list,0);
          insert_node(&list,temp,list.numberOfElements);
        }
      }else{
        time_now++;
        while(time_now==at[ind]){
          insert_node(&list,ind,list.numberOfElements);
          ind++;
          if (ind > n-1) {
            break;
          }
        }
      } 
    }
    
    printf("\nP#\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0;i<n;i++){
        tat = tat+(ct_arr[i]-at[i]);
        wt = wt+(ct_arr[i]-at[i]-bt[i]);
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),at[i],bt[i],ct_arr[i],(ct_arr[i]-at[i]),(ct_arr[i]-at[i]-bt[i]));
    }
    printf("Average Turnaround time: %f\n",(tat/n));
    printf("Average waiting time %f\n",(wt/n));
}

