#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        return 1;
    }

    if (write(fd, "Hello, World!", 13) == -1) {
        close(fd);
        return 2;
    }

    close(fd);
    return 0;
}