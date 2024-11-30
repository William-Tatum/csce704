#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg) {
    char username[128];
    pthread_mutex_lock(&mutex);
    char *login_name = getlogin();
    if (login_name != NULL) {
        strncpy(username, login_name, sizeof(username) - 1);
        username[sizeof(username) - 1] = '\0';
        printf("Username: %s\n", username);
    } else {
        fprintf(stderr, "Failed to get login name\n");
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}