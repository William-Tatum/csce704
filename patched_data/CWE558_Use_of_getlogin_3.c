#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>

void print_username() {
    struct passwd *pw;
    uid_t uid;
    uid = geteuid();
    errno = 0;
    pw = getpwuid(uid);
    if (pw) {
        printf("Username: %s\n", pw->pw_name);
    } else {
        if (errno != 0) {
            perror("getpwuid");
        } else {
            printf("No username found for UID %d\n", uid);
        }
    }
}

int main() {
    print_username();
    return 0;
}