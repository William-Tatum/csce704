#include <unistd.h>
#include <limits.h>
#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* print_username(void* arg) {
    struct passwd pwd;
    struct passwd *result;
    char *buf;
    size_t bufsize;
    uid_t uid;
    
    uid = geteuid();
    bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
    if (bufsize == -1) {
        bufsize = 16384;
    }

    buf = malloc(bufsize);
    if (buf == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (getpwuid_r(uid, &pwd, buf, bufsize, &result) == 0 && result != NULL) {
        pthread_mutex_lock(&lock);
        printf("Username: %s\n", pwd.pw_name);
        pthread_mutex_unlock(&lock);
    } else {
        perror("getpwuid_r");
    }

    free(buf);
    return NULL;
}

int main() {
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        if (pthread_create(&threads[i], NULL, print_username, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}