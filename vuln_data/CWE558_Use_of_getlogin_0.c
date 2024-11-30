#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>

void* print_username(void* arg) {
    struct passwd *pw;
    uid_t uid;

    uid = geteuid();
    pw = getpwuid(uid);

    if (pw) {
        printf("User: %s\n", pw->pw_name);
    } else {
        printf("Failed to obtain username\n");
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