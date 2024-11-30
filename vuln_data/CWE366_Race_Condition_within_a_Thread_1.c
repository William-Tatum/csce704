#include <stdio.h>
#include <pthread.h>

int counter = 0;

void* increment_counter(void* args) {
    for (int i = 0; i < 10000; i++) {
        int tmp = counter;
        tmp = tmp + 1;
        counter = tmp;
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
    return 0;
}