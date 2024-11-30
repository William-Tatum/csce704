#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    for(int i = 0; i < 1000000; i++) {
        if (pthread_mutex_lock(&lock) != 0) {
            perror("Mutex lock failed");
            return NULL;
        }
        counter++;
        if (pthread_mutex_unlock(&lock) != 0) {
            perror("Mutex unlock failed");
            return NULL;
        }
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex init failed");
        return 1;
    }
    if (pthread_create(&t1, NULL, increment, NULL) != 0) {
        perror("Thread creation failed");
        return 1;
    }
    if (pthread_create(&t2, NULL, increment, NULL) != 0) {
        perror("Thread creation failed");
        return 1;
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final counter value: %d\n", counter);
    pthread_mutex_destroy(&lock);
    return 0;
}