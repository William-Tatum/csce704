#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int shared_resource = 0;
pthread_mutex_t resource_mutex;

void* increment_resource(void* arg) {
    pthread_mutex_lock(&resource_mutex);
    shared_resource++;
    pthread_mutex_unlock(&resource_mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    if (pthread_mutex_init(&resource_mutex, NULL) != 0) {
        fprintf(stderr, "Mutex initialization failed\n");
        return 1;
    }

    if (pthread_create(&thread1, NULL, increment_resource, NULL) != 0) {
        fprintf(stderr, "Thread creation failed\n");
        return 1;
    }
    if (pthread_create(&thread2, NULL, increment_resource, NULL) != 0) {
        fprintf(stderr, "Thread creation failed\n");
        return 1;
    }

    if (pthread_join(thread1, NULL) != 0) {
        fprintf(stderr, "Thread join failed\n");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0) {
        fprintf(stderr, "Thread join failed\n");
        return 1;
    }

    printf("Final value of shared resource: %d\n", shared_resource);
    
    if (pthread_mutex_destroy(&resource_mutex) != 0) {
        fprintf(stderr, "Mutex destruction failed\n");
        return 1;
    }
    
    return 0;
}