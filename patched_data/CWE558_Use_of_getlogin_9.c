#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>

void print_username() {
    struct passwd *pw;
    uid_t uid;
    char username[1024];

    uid = geteuid();
    pw = getpwuid(uid);
    if (pw) {
        if (snprintf(username, sizeof(username), "%s", pw->pw_name) >= sizeof(username)) {
            fprintf(stderr, "Username is too long\n");
            exit(EXIT_FAILURE);
        }
        printf("Username: %s\n", username);
    } else {
        perror("getpwuid");
        exit(EXIT_FAILURE);
    }
}

int main() {
    print_username();
    return 0;
}