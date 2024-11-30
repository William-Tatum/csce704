#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void *thread_function(void *arg) {
    char username[128];
    strncpy(username, getlogin(), sizeof(username) - 1);
    username[sizeof(username) - 1] = '\0';
    printf("Username: %s\n", username);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}