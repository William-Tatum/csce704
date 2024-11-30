#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>

void* print_username(void* arg) {
    struct passwd *pw;
    char username[256];

    pw = getpwuid(geteuid());
    if (pw != NULL) {
        strncpy(username, pw->pw_name, sizeof(username) - 1);
        username[sizeof(username) - 1] = '\0';
        printf("Logged in user: %s\n", username);
    } else {
        printf("Failed to get username.\n");
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