#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int shared_resource = 0;
pthread_mutex_t lock;

void* increment_resource(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        pthread_mutex_lock(&lock);
        ++shared_resource;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex initialization failed");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread1, NULL, increment_resource, NULL) != 0) {
        perror("Thread creation failed");
        pthread_mutex_destroy(&lock);
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread2, NULL, increment_resource, NULL) != 0) {
        perror("Thread creation failed");
        pthread_join(thread1, NULL);
        pthread_mutex_destroy(&lock);
        exit(EXIT_FAILURE);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared resource: %d\n", shared_resource);

    pthread_mutex_destroy(&lock);
    return 0;
}