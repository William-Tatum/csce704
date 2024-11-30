#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <limits.h>
#include <errno.h>

int main() {
    struct passwd *pw;
    uid_t uid;
    uid = geteuid();
    errno = 0;
    pw = getpwuid(uid);
    if (!pw) {
        if (errno) {
            perror("getpwuid");
        } else {
            fprintf(stderr, "User ID not found\n");
        }
        return 1;
    }
    
    if (pw->pw_name == NULL || strlen(pw->pw_name) == 0) {
        fprintf(stderr, "Failed to retrieve username\n");
        return 1;
    }

    printf("Username: %s\n", pw->pw_name);
    return 0;
}