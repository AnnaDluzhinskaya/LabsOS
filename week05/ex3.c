#include <stdio.h>
#include <pthread.h>

int buffer_size = 5000, count = 0, p_work = 0, c_work = 0;

void producer() {
    while (1) {
        if (buffer_size == count) {
            p_work = 0;
            printf("Producer: sleeping\n");
            while(!p_work) {}
        } else {
            count++;
            if (count == 1) {
                printf("Consumer: starts working\n");
                c_work = 1;
            }
        }

    }
}

void consumer(){
    while (1) {
        if (count == 0) {
            c_work = 0;
            printf("Consumer: sleeping\n");
            while(!c_work) {}
        } else {
            count--;
            if (count == 0) {
                printf("Producer: starts working\n");
                p_work = 1;
            }
        }

    }
}

int main() {
    pthread_t *producer, *consumer;
    pthread_create(&producer, NULL, &producer, NULL);
    pthread_create(&consumer, NULL, &consumer, NULL);
    pthread_join(&consumer, 0);
    pthread_join(&producer, 0);

}

