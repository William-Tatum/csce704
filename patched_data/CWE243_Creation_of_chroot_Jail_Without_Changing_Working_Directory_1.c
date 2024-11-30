#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (geteuid() != 0) {
        fprintf(stderr, "Program must be run as root\n");
        exit(EXIT_FAILURE);
    }

    if (chdir("/new/root") != 0) {
        perror("chdir to new root failed");
        exit(EXIT_FAILURE);
    }

    if (chroot(".") != 0) {
        perror("chroot failed");
        exit(EXIT_FAILURE);
    }

    if (chdir("/") != 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }

    printf("Chroot jail and change directory set up successfully\n");

    return 0;
}