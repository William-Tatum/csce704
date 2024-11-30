#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int shared_counter = 0;

void* increment_counter(void* arg) {
    for(int i = 0; i < 1000000; i++) {
        shared_counter++;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    if(pthread_create(&thread1, NULL, increment_counter, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    if(pthread_create(&thread2, NULL, increment_counter, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    if(pthread_join(thread1, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    if(pthread_join(thread2, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    printf("Final counter value: %d\n", shared_counter);
    return 0;
}