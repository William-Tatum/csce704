#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int shared_resource = 0;
pthread_mutex_t lock;

void *thread_func(void *arg) {
    pthread_mutex_lock(&lock);
    shared_resource++;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init failed\n");
        return 1;
    }

    pthread_t tid1, tid2;

    if (pthread_create(&tid1, NULL, thread_func, NULL) != 0) {
        printf("Thread creation failed\n");
        return 1;
    }
    if (pthread_create(&tid2, NULL, thread_func, NULL) != 0) {
        printf("Thread creation failed\n");
        return 1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Final value of shared resource: %d\n", shared_resource);

    pthread_mutex_destroy(&lock);

    return 0;
}