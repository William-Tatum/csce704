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

    pthread_create(&thread1, NULL, increment_resource, NULL);
    pthread_create(&thread2, NULL, decrement_resource, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_resource: %d\n", shared_resource);

    pthread_mutex_destroy(&resource_mutex);
    return 0;
}