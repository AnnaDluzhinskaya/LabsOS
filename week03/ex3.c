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
    index--;
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

int main() {
    printf("Create linked list\n");
    struct List linkedList;// Create linked list
    linkedList.numberOfElements = 0;// Initialize size of list as 0

    printf("Try to print list of elements, but \n");
    print_list(&linkedList);//Try to print list of elements

    printf("Add elements (2, 3 and 4) into linked list\n");
    //Add elements (1, 2 and 3) into linked list
    insert_node(&linkedList,2,0);
    insert_node(&linkedList,3,1);
    insert_node(&linkedList,4,2);

    //Print list of elements
    print_list(&linkedList);

    printf("Add elements (4, 5, 6 and 7) into linked list\n");
    //Add elements (4, 5, 6 and 7) into linked list
    insert_node(&linkedList,5,3);
    insert_node(&linkedList,6,4);
    insert_node(&linkedList,7,5);
    insert_node(&linkedList,8,6);

    //Print list of elements one more time
    print_list(&linkedList);

    printf("Delete first and last elements\n");
    //Delete elements from linked list
    delete_node(&linkedList, 7);
    delete_node(&linkedList, 1);

    //Try to delete element which is not exist, the program ignore this command
    delete_node(&linkedList, 7);

    //Print list of elements after changes
    print_list(&linkedList);

}
