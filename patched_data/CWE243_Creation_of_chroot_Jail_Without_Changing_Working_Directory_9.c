#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main() {
    if (getuid() != 0) {
        fprintf(stderr, "Root privileges are required\n");
        exit(1);
    }

    if (chroot("/var/jail") != 0) {
        perror("chroot failed");
        exit(1);
    }
    if (chdir("/") != 0) {
        perror("chdir failed");
        exit(1);
    }

    struct passwd *pw = getpwnam("nobody");
    if (pw == NULL) {
        fprintf(stderr, "Failed to get user information for 'nobody'\n");
        exit(1);
    }

    if (setgid(pw->pw_gid) != 0) {
        perror("setgid failed");
        exit(1);
    }

    if (setuid(pw->pw_uid) != 0) {
        perror("setuid failed");
        exit(1);
    }

    return 0;
}