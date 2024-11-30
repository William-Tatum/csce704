#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void* print_username(void* arg) {
    char *username = getlogin();
    if (username) {
        printf("Username: %s\n", username);
    } else {
        perror("getlogin failed");
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, print_username, NULL) != 0) {
        perror("Failed to create thread1");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread2, NULL, print_username, NULL) != 0) {
        perror("Failed to create thread2");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}