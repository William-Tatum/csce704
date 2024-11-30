#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* print_username(void* arg) {
    char* user = getlogin();
    printf("Logged in user: %s\n", user);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, print_username, NULL);
    pthread_create(&thread2, NULL, print_username, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}