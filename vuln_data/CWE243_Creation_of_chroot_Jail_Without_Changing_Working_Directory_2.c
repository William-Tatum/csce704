#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    if (chroot("/path/to/jail") != 0) {
        perror("Failed to chroot");
        exit(EXIT_FAILURE);
    }
    if (chdir("/") != 0) {
        perror("Failed to change working directory");
        exit(EXIT_FAILURE);
    }
    // Rest of the program logic
    return 0;
}