#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        return 1;
    }

    close(fd);

    if (write(fd, "This won't be written\n", 22) == -1) {
        perror("write failed");
    }

    return 0;
}