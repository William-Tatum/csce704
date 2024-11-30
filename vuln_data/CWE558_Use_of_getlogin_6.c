#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>

int main() {
    struct passwd *pw;
    uid_t uid;
    uid = geteuid();
    pw = getpwuid(uid);
    if (pw) {
        printf("Username: %s\n", pw->pw_name);
    } else {
        perror("getpwuid");
        return 1;
    }
    return 0;
}