#include <pthread.h>
#include <stdio.h>

int shared_resource = 0;
pthread_mutex_t lock;

void* thread_function(void* arg) {
    pthread_mutex_lock(&lock);
    int temp = shared_resource;
    temp = temp + 1;
    shared_resource = temp;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);

    printf("Final value of shared_resource: %d\n", shared_resource);
    return 0;
}