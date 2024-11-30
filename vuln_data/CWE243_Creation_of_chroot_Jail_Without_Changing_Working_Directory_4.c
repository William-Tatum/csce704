#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (chdir("/newroot") != 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }

    if (chroot("/newroot") != 0) {
        perror("chroot failed");
        exit(EXIT_FAILURE);
    }

    if (chdir("/") != 0) {
        perror("chdir to / failed");
        exit(EXIT_FAILURE);
    }

    // Further code execution within the chroot jail

    return 0;
}