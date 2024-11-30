#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    if (write(fd, "This will be written\n", 21) == -1) {
        perror("write failed");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("close failed");
        return 1;
    }

    return 0;
}