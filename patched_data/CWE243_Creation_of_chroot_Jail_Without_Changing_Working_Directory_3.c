#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (geteuid() != 0) {
        fprintf(stderr, "Error: This program must be run as root.\n");
        return 1;
    }

    if (chroot("/newroot") != 0) {
        perror("chroot failed");
        return 1;
    }

    if (chdir("/") != 0) {
        perror("chdir failed");
        return 1;
    }

    if (setuid(geteuid()) != 0) {
        perror("setuid failed");
        return 1;
    }

    return 0;
}