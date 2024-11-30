#include <pthread.h>
#include <stdio.h>

int sharedResource = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* incrementer(void* arg) {
    for (int i = 0; i < 1000000; ++i) {
        pthread_mutex_lock(&mutex);
        sharedResource++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* decrementer(void* arg) {
    for (int i = 0; i < 1000000; ++i) {
        pthread_mutex_lock(&mutex);
        sharedResource--;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, incrementer, NULL);
    pthread_create(&thread2, NULL, decrementer, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    printf("Final Value: %d\n", sharedResource);
    return 0;
}