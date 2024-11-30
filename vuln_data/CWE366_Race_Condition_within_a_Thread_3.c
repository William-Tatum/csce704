#include <stdio.h>
#include <pthread.h>

volatile int shared_resource = 0;

void* race_condition_example(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        int temp = shared_resource;
        temp++;
        shared_resource = temp;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, race_condition_example, NULL);
    pthread_create(&thread2, NULL, race_condition_example, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_resource: %d\n", shared_resource);
    return 0;
}