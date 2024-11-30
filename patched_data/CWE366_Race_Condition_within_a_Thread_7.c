#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int shared_resource = 0;
pthread_mutex_t lock;

void *thread_func(void *arg) {
    pthread_mutex_lock(&lock);
    int local_resource = shared_resource;
    local_resource++;
    sleep(1);
    shared_resource = local_resource;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Shared Resource: %d\n", shared_resource);
    pthread_mutex_destroy(&lock);
    return 0;
}