
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct Node{
    int value;
    unsigned int r_bit;
    struct Node *next;
};

struct List {
    struct Node *head;
    struct Node *tail;
    int numberOfElements;
};

void print_memory(struct List *list, int page_frame){
  struct Node *temp = list->head;
  for (int i = 0; i < page_frame; i++) {
      if (i < list->numberOfElements){
        printf("i = %d id = %d %d\n",i,temp->value,temp->r_bit);
        temp = temp->next;
      }else{
        printf("i = %d id = -1 0\n",i);
      }
  }
}

int find_min(struct List *list){
    struct Node *temp; 
    int min = (int)(pow(2,16));
    int index = 0;
    temp = list->head; 
    for(int i=0;i<list->numberOfElements;i++){
        if (temp->r_bit<min){
          min = temp->r_bit;
          index = i;
        }
        temp = temp -> next; 
    }
    return index;
}

struct Node* find(struct List *list,int page_index){
    struct Node *temp; 
    temp = list->head; 
    int i = 0;
    while(temp->value!=page_index){
        i++;
        if (i == list->numberOfElements) {
            break;
        }
        temp = temp -> next;
    }
    if (temp->value==page_index){
      return temp;
    }else{
      return NULL;
    }
}

struct Node* get(struct List *list,int index){
    struct Node *temp; 
    temp = list->head; 
    for (int i = 0; i < index; i++){
        temp = temp -> next; 
    }
    return temp; 
}

void replace_node(struct Node *node, int index){
    node->value=index;
    node->r_bit=(int)(pow(2,15));
}

void insert_page(struct List *list, int item, int index){
    if (index == 0){
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->value = item;
        newNode->r_bit = (int)(pow(2,15));
        list->head = newNode;
        list->tail = newNode;
        list->numberOfElements+=1;
    }else{
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode -> value = item;
        newNode->r_bit = (int)(pow(2,15));

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

void tic(struct List *list){
  struct Node *temp = list->head;
  for (int i = 0; i < list->numberOfElements; i++){
    temp -> r_bit = (temp -> r_bit)/2;
    temp = temp -> next;
  }
}

int main () { 
  char *str = malloc(256*sizeof(char));
  printf("Print number of pages: \n");
  fgets(str, 256, stdin);
  int page_frame = 100;
  page_frame = atoi(str);
  int page = 0;
  int hit = 0, miss = 0;
  struct List memory;
  memory.numberOfElements = 0;
  struct Node *temp = NULL;

  FILE* stream = fopen("input.txt", "r");
  while (fscanf(stream, "%s ", str) != EOF) {
    page = atoi(str);
    print_memory(&memory,page_frame);
    printf("current page number %d\n\n",page);
    printf("\n");
    
    if (memory.numberOfElements>0){
      temp = find(&memory,page);
    }

    

    if(temp==NULL){
      miss++;
      if(memory.numberOfElements<page_frame){
        tic(&memory);
        insert_page(&memory,page,memory.numberOfElements);
      }else{
        tic(&memory);
        replace_node(get(&memory,find_min(&memory)),page);
       
      }
    }else{
      hit++;
      tic(&memory);
      temp -> r_bit = (temp -> r_bit)+(unsigned int)(pow(2,15));
    }
  }

  printf("hit = %d miss = %d hit/miss = %f\n",hit,miss,(double)hit/(double)miss);
  
  
}