#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_resource = 0;

void* increment_resource(void* arg) {
    for(int i = 0; i < 100000; i++) {
        int temp = shared_resource;
        temp++;
        usleep(1); 
        shared_resource = temp;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment_resource, NULL);
    pthread_create(&thread2, NULL, increment_resource, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Shared resource final value: %d\n", shared_resource);
    return 0;
}