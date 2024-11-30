#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>

int main() {
    if (geteuid() != 0) {
        fprintf(stderr, "This program must be run as root\n");
        exit(EXIT_FAILURE);
    }

    if (chroot("/path/to/jail") != 0) {
        perror("chroot failed");
        exit(EXIT_FAILURE);
    }

    if (chdir("/") != 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }

    if (setuid(0) != 0) {
        perror("setuid failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        pause(); // Suspend execution until a signal is received
    }

    return 0;
}