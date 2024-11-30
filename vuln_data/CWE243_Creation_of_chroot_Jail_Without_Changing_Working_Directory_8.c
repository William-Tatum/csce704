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

    // Now the process runs inside the chroot jail with the working directory properly set.
    // Further implementation code goes here.

    return 0;
}