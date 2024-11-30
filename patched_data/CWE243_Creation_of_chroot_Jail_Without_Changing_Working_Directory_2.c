#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

int main() {
    if (geteuid() != 0) {
        fprintf(stderr, "This program must be run as root.\n");
        exit(EXIT_FAILURE);
    }

    if (chroot("/path/to/jail") != 0) {
        perror("Failed to chroot");
        exit(EXIT_FAILURE);
    }

    if (chdir("/") != 0) {
        perror("Failed to change working directory");
        exit(EXIT_FAILURE);
    }

    if (setuid(getuid()) != 0) {
        perror("Failed to drop privileges");
        exit(EXIT_FAILURE);
    }

    // Rest of the program logic
    return 0;
}