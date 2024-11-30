#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (chroot("/path/to/jail") != 0) {
        perror("chroot failed");
        exit(EXIT_FAILURE);
    }

    if (chdir("/") != 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }

    // Now the process is confined to the new root and current directory is /
    while (1) {
        // The process runs within the chroot jail
    }

    return 0;
}