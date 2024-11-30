#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <stdlib.h>

#define NUM_THREADS 5

void* print_username(void* arg) {
    struct passwd *pw;
    char username[256];
    uid_t uid = getuid();
    struct passwd pwd;
    char buffer[1024];
    
    if (getpwuid_r(uid, &pwd, buffer, sizeof(buffer), &pw) == 0 && pw != NULL) {
        strncpy(username, pw->pw_name, sizeof(username) - 1);
        username[sizeof(username) - 1] = '\0';
        printf("Thread %ld: Username = %s\n", (long)arg, username);
    } else {
        printf("Thread %ld: Unable to get username\n", (long)arg);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, print_username, (void*)i);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}