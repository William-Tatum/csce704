#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (chroot("/new_root") != 0) {
        perror("chroot failed");
        exit(EXIT_FAILURE);
    }
    if (chdir("/") != 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }
    // Code that operates within the chroot jail
    return 0;
}