#include <stdio.h>
#include <pthread.h>

int shared_resource = 0;
pthread_mutex_t lock;

void *increment_resource(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&lock);
        shared_resource++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void *decrement_resource(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&lock);
        shared_resource--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    if (pthread_mutex_init(&lock, NULL) != 0) {
        fprintf(stderr, "Mutex init failed\n");
        return 1;
    }

    if (pthread_create(&t1, NULL, increment_resource, NULL) != 0) {
        fprintf(stderr, "Failed to create thread t1\n");
        pthread_mutex_destroy(&lock);
        return 1;
    }

    if (pthread_create(&t2, NULL, decrement_resource, NULL) != 0) {
        fprintf(stderr, "Failed to create thread t2\n");
        pthread_join(t1, NULL);
        pthread_mutex_destroy(&lock);
        return 1;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value of shared_resource: %d\n", shared_resource);

    pthread_mutex_destroy(&lock);
    return 0;
}