#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    if (geteuid() != 0) {
        fprintf(stderr, "Must be run as root\n");
        exit(EXIT_FAILURE);
    }

    if (chroot("/new_root") != 0) {
        perror("chroot failed");
        exit(EXIT_FAILURE);
    }

    if (chdir("/") != 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }

    if (setuid(geteuid()) != 0) {
        perror("setuid failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}