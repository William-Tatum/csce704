#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    const char *new_root = "/path/to/jail";

    // Ensure the program is running as root
    if (geteuid() != 0) {
        fprintf(stderr, "This program must be run as root\n");
        exit(EXIT_FAILURE);
    }

    // Call chdir() before chroot() to minimize privilege escalation risks
    if (chdir(new_root) != 0) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    if (chroot(new_root) != 0) {
        perror("chroot");
        exit(EXIT_FAILURE);
    }

    if (chdir("/") != 0) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    // Drop root privileges after entering the chroot jail
    if (setgid(getgid()) != 0 || setuid(getuid()) != 0) {
        perror("Dropping privileges failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}