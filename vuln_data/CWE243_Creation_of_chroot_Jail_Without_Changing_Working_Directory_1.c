#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (chroot("/new/root") != 0) {
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