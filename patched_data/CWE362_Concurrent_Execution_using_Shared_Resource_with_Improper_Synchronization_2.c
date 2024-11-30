#include <pthread.h>
#include <stdio.h>

int shared_resource = 0;
pthread_mutex_t lock;

void* thread_func(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        pthread_mutex_lock(&lock);
        shared_resource++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        fprintf(stderr, "Mutex initialization failed\n");
        return 1;
    }

    if (pthread_create(&thread1, NULL, thread_func, NULL) != 0) {
        fprintf(stderr, "Error creating thread1\n");
        pthread_mutex_destroy(&lock);
        return 1;
    }
    
    if (pthread_create(&thread2, NULL, thread_func, NULL) != 0) {
        fprintf(stderr, "Error creating thread2\n");
        pthread_join(thread1, NULL);
        pthread_mutex_destroy(&lock);
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);

    printf("Final value of shared resource: %d\n", shared_resource);

    return 0;
}