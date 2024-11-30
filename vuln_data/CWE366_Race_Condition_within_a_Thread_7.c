#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int shared_resource = 0;

void *thread_func(void *arg) {
    int local_resource;
    local_resource = shared_resource;
    local_resource++;
    sleep(1);
    shared_resource = local_resource;
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Shared Resource: %d\n", shared_resource);
    return 0;
}