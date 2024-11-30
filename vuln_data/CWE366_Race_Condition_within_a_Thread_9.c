#include <stdio.h>
#include <pthread.h>

volatile int shared_resource = 0;

void* thread_func(void* arg) {
    for(int i = 0; i < 1000000; i++) {
        shared_resource++;
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
    return 0;
}