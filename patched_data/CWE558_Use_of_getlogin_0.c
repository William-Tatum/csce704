#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <stdlib.h>

void* print_username(void* arg) {
    struct passwd pwd;
    struct passwd *result;
    uid_t uid;
    char buf[1024];
    int s;

    uid = geteuid();
    s = getpwuid_r(uid, &pwd, buf, sizeof(buf), &result);
    if (result == NULL) {
        if (s == 0)
            printf("No matching username found\n");
        else
            printf("getpwuid_r error: %d\n", s);
    } else {
        printf("User: %s\n", pwd.pw_name);
    }

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