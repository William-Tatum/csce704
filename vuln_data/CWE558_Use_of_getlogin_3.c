#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

void print_username() {
    struct passwd *pw;
    uid_t uid;
    uid = geteuid();
    pw = getpwuid(uid);
    if (pw) {
        printf("Username: %s\n", pw->pw_name);
    } else {
        printf("Failed to get username\n");
    }
}

int main() {
    print_username();
    return 0;
}