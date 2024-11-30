#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int shared_resource = 0;
pthread_mutex_t resource_mutex;

void* increment_resource(void* arg) {
    pthread_mutex_lock(&resource_mutex);
    int temp = shared_resource;
    temp++;
    shared_resource = temp;
    pthread_mutex_unlock(&resource_mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&resource_mutex, NULL);

    pthread_create(&thread1, NULL, increment_resource, NULL);
    pthread_create(&thread2, NULL, increment_resource, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared resource: %d\n", shared_resource);
    
    pthread_mutex_destroy(&resource_mutex);
    return 0;
}