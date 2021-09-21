#include <stdio.h>
#include <pthread.h>

void someMessage(int n){
    printf("Message from tread №%d\n",n);
}

void createMessage(int n){
    printf("Tread №%d was created\n",n);
}

void doneMessage(int n){
    printf("Tread №%d is done\n",n);
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; ++i) {
        createMessage(i+1);
        pthread_create(&threads[i],NULL,&someMessage,i+1);
        pthread_join(threads[i],0);
        doneMessage(i+1);
    }
}

