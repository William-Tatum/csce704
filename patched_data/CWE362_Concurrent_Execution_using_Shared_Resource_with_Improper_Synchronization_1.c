#include <stdio.h>
#include <pthread.h>

int sharedResource = 0;
pthread_mutex_t lock;

void* increment_resource(void* args) {
    pthread_mutex_lock(&lock);
    printf("Current value: %d\n", sharedResource);
    sharedResource++;
    printf("Incremented value: %d\n", sharedResource);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    if (pthread_create(&thread1, NULL, increment_resource, NULL) != 0) {
        printf("Thread creation failed.\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, increment_resource, NULL) != 0) {
        printf("Thread creation failed.\n");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);
    printf("Final value: %d\n", sharedResource);

    return 0;
}