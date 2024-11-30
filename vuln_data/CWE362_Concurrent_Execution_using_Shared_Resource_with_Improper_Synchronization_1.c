#include <stdio.h>
#include <pthread.h>

int sharedResource = 0;
pthread_mutex_t lock;

void* increment_resource(void* args) {
    pthread_mutex_lock(&lock);
    int temp = sharedResource;
    printf("Current value: %d\n", temp);
    temp++;
    sharedResource = temp;
    printf("Incremented value: %d\n", sharedResource);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, increment_resource, NULL);
    pthread_create(&thread2, NULL, increment_resource, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    pthread_mutex_destroy(&lock);
    printf("Final value: %d\n", sharedResource);

    return 0;
}