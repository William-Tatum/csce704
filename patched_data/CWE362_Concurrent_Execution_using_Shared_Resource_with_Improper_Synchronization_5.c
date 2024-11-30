#include <stdio.h>
#include <pthread.h>

int shared_resource = 0;
pthread_mutex_t lock;

void* thread_function(void* arg) {
    pthread_mutex_lock(&lock);
    shared_resource++;
    printf("Shared resource value: %d\n", shared_resource);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex initialization failed");
        return 1;
    }

    if (pthread_create(&thread1, NULL, thread_function, NULL) != 0) {
        perror("Thread creation failed");
        pthread_mutex_destroy(&lock);
        return 1;
    }

    if (pthread_create(&thread2, NULL, thread_function, NULL) != 0) {
        perror("Thread creation failed");
        pthread_join(thread1, NULL);
        pthread_mutex_destroy(&lock);
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}