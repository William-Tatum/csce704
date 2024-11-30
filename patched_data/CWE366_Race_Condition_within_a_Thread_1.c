#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void* increment_counter(void* args) {
    for (int i = 0; i < 10000; i++) {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Counter: %d\n", counter);
    pthread_mutex_destroy(&counter_mutex);
    return 0;
}