#include <pthread.h>
#include <stdio.h>

int shared_resource = 0;
pthread_mutex_t lock;

void* thread_function(void* arg) {
    pthread_mutex_lock(&lock);
    shared_resource += 1;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        fprintf(stderr, "Mutex init failed\n");
        return 1;
    }

    if (pthread_create(&thread1, NULL, thread_function, NULL) != 0) {
        fprintf(stderr, "Failed to create thread1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, thread_function, NULL) != 0) {
        fprintf(stderr, "Failed to create thread2\n");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);

    printf("Final value of shared_resource: %d\n", shared_resource);
    return 0;
}