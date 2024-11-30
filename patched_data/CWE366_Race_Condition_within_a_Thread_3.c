#include <stdio.h>
#include <pthread.h>

volatile int shared_resource = 0;
pthread_mutex_t lock;

void* race_condition_example(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        pthread_mutex_lock(&lock);
        int temp = shared_resource;
        temp++;
        shared_resource = temp;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, race_condition_example, NULL);
    pthread_create(&thread2, NULL, race_condition_example, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_resource: %d\n", shared_resource);

    pthread_mutex_destroy(&lock);
    return 0;
}