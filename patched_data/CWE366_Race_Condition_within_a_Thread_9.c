#include <stdio.h>
#include <pthread.h>

volatile int shared_resource = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_func(void* arg) {
    for(int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&mutex);
        shared_resource++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final value of shared_resource: %d\n", shared_resource);
    pthread_mutex_destroy(&mutex);
    return 0;
}