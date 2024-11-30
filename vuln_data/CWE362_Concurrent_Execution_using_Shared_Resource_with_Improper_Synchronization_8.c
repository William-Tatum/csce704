#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int shared_resource = 0;
pthread_mutex_t resource_mutex;

void* thread_function(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&resource_mutex);
        shared_resource++;
        pthread_mutex_unlock(&resource_mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&resource_mutex, NULL);

    if (pthread_create(&thread1, NULL, thread_function, NULL) != 0) {
        perror("Failed to create thread1");
        exit(1);
    }

    if (pthread_create(&thread2, NULL, thread_function, NULL) != 0) {
        perror("Failed to create thread2");
        exit(1);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_resource: %d\n", shared_resource);

    pthread_mutex_destroy(&resource_mutex);
    return 0;
}