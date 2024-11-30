#define _GNU_SOURCE
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

    if (chdir("/new/root/directory") != 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }

    if (chroot(".") != 0) {
        perror("chroot failed");
        exit(EXIT_FAILURE);
    }

    if (setuid(getuid()) != 0) {
        perror("setuid failed");
        exit(EXIT_FAILURE);
    }

    if (chdir("/") != 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}