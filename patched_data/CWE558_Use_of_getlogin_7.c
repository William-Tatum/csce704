#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 1024

pthread_mutex_t lock;

void* print_username(void* arg) {
    struct passwd *pw;
    struct passwd pwd;
    char buf[BUFFER_SIZE];
    char username[BUFFER_SIZE];

    uid_t uid = geteuid();

    pthread_mutex_lock(&lock);
    int ret = getpwuid_r(uid, &pwd, buf, BUFFER_SIZE, &pw);
    pthread_mutex_unlock(&lock);

    if (ret == 0 && pw) {
        strncpy(username, pw->pw_name, BUFFER_SIZE - 1);
        username[BUFFER_SIZE - 1] = '\0';
        printf("Username: %s\n", username);
    } else {
        printf("Failed to get username: %s\n", strerror(errno));
    }
    return NULL;
}

int main() {
    pthread_t threads[5];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 5; ++i) {
        pthread_create(&threads[i], NULL, print_username, NULL);
    }
    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}