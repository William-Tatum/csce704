#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    // Use of expired file descriptor
    if (write(fd, "Hello, World!\n", 14) == -1) {
        perror("write");
    }

    return 0;
}