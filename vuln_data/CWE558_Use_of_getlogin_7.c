#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void* print_username(void* arg) {
    struct passwd *pw;
    uid_t uid = geteuid();
    pw = getpwuid(uid);
    char username[BUFFER_SIZE];
    if (pw) {
        strncpy(username, pw->pw_name, BUFFER_SIZE - 1);
        username[BUFFER_SIZE - 1] = '\0';
        printf("Username: %s\n", username);
    } else {
        printf("Failed to get username\n");
    }
    return NULL;
}

int main() {
    pthread_t threads[5];
    for (int i = 0; i < 5; ++i) {
        pthread_create(&threads[i], NULL, print_username, NULL);
    }
    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}