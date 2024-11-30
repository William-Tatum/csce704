#include <stdio.h>
#include <pthread.h>

int shared_resource = 0;
pthread_mutex_t resource_mutex = PTHREAD_MUTEX_INITIALIZER;

void* increment_resource(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&resource_mutex);
        shared_resource++;
        pthread_mutex_unlock(&resource_mutex);
    }
    return NULL;
}

void* decrement_resource(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&resource_mutex);
        shared_resource--;
        pthread_mutex_unlock(&resource_mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, increment_resource, NULL) != 0) {
        fprintf(stderr, "Error creating thread1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, decrement_resource, NULL) != 0) {
        fprintf(stderr, "Error creating thread2\n");
        pthread_cancel(thread1);
        return 1;
    }

    if (pthread_join(thread1, NULL) != 0) {
        fprintf(stderr, "Error joining thread1\n");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0) {
        fprintf(stderr, "Error joining thread2\n");
        return 1;
    }

    printf("Final value of shared_resource: %d\n", shared_resource);

    pthread_mutex_destroy(&resource_mutex);
    return 0;
}